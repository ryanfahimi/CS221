/**
 * climate.c
 *
 * Performs analysis on climate data provided by the
 * National Oceanic and Atmospheric Administration (NOAA).
 *
 * Input:    Tab-delimited file(s) to analyze.
 * Output:   Summary information about the data.
 *
 * Compile:  run make
 *
 * Example Run:      ./climate data_tn.tdv data_wa.tdv
 *
 *
 * Opening file: data_tn.tdv
 * Opening file: data_wa.tdv
 * States found: TN WA
 * -- State: TN --
 * Number of Records: 17097
 * Average Humidity: 49.4%
 * Average Temperature: 58.3F
 * Max Temperature: 110.4F
 * Max Temperature on: Mon Aug  3 11:00:00 2015
 * Min Temperature: -11.1F
 * Min Temperature on: Fri Feb 20 04:00:00 2015
 * Lightning Strikes: 781
 * Records with Snow Cover: 107
 * Average Cloud Cover: 53.0%
 * -- State: WA --
 * Number of Records: 48357
 * Average Humidity: 61.3%
 * Average Temperature: 52.9F
 * Max Temperature: 125.7F
 * Max Temperature on: Sun Jun 28 17:00:00 2015
 * Min Temperature: -18.7F
 * Min Temperature on: Wed Dec 30 04:00:00 2015
 * Lightning Strikes: 1190
 * Records with Snow Cover: 1383
 * Average Cloud Cover: 54.5%
 *
 * TDV format:
 *
 * CA» 1428300000000»  9prcjqk3yc80»   93.0»   0.0»100.0» 0.0»95644.0»277.58716
 * CA» 1430308800000»  9prc9sgwvw80»   4.0»0.0»100.0»  0.0»99226.0»282.63037
 * CA» 1428559200000»  9prrremmdqxb»   61.0»   0.0»0.0»0.0»102112.0» 285.07513
 * CA» 1428192000000»  9prkzkcdypgz»   57.0»   0.0»100.0»  0.0»101765.0»
 * 285.21332 CA» 1428170400000»  9prdd41tbzeb»   73.0»   0.0»22.0»
 * 0.0»102074.0» 285.10425 CA» 1429768800000»  9pr60tz83r2p»   38.0»
 * 0.0»0.0»0.0»101679.0»   283.9342 CA» 1428127200000»  9prj93myxe80»   98.0»
 * 0.0»100.0»  0.0»102343.0» 285.75 CA» 1428408000000»  9pr49b49zs7z»   93.0»
 * 0.0»100.0»  0.0»100645.0» 285.82413
 *
 * Each field is separated by a tab character \t and ends with a newline \n.
 *
 * Fields:
 *      state code (e.g., CA, TX, etc),
 *      timestamp (time of observation as a UNIX timestamp),
 *      geolocation (geohash string),
 *      humidity (0 - 100%),
 *      snow (1 = snow present, 0 = no snow),
 *      cloud cover (0 - 100%),
 *      lightning strikes (1 = lightning strike, 0 = no lightning),
 *      pressure (Pa),
 *      surface temperature (Kelvin)
 */

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_STATES 50

typedef struct climate_info climate;

struct climate_info
{
  char code[3];
  unsigned long num_records;
  long double sum_temp;
  long double sum_humidity;
  double max_temp;
  double min_temp;
  unsigned long max_temp_timestamp;
  unsigned long min_temp_timestamp;
  unsigned long num_lightning;
  unsigned long num_snow;
  long double sum_cloud;
};

void analyze_file (FILE *file, struct climate_info *states[], int num_states);
void print_report (struct climate_info *states[], int num_states);
climate *init_climate (climate *states[], int num_states, char *code);
climate *get_climate (climate *states[], int num_states, char *code);
void update_climate (climate *info);
void free_states (climate *states[], int num_states);

int
main (int argc, char *argv[])
{

  /* You should be able to read multiple files. */
  if (argc < 2)
    {
      printf ("Usage: %s tdv_file1 tdv_file2 ... tdv_fileN \n", argv[0]);
      return EXIT_FAILURE;
    }

  /* Let's create an array to store our state data in. As we know, there are
   * 50 US states. */
  climate *states[NUM_STATES] = { NULL };
  int error = 0;

  int i;
  for (i = 1; i < argc; ++i)
    {
      /* Open the file for reading */
      FILE *file = fopen (argv[i], "r");
      /* If the file doesn't exist, print an error message and move on
       * to the next file. */
      if (file == NULL)
        {
          printf ("Error opening file: %s\n", argv[i]);
          error = 1;
          continue;
        }
      /* Analyze the file */
      analyze_file (file, states, NUM_STATES);
      fclose (file);
    }

  /* Now that we have recorded data for each file, we'll summarize them: */
  print_report (states, NUM_STATES);

  free_states (states, NUM_STATES);

  if (error)
    {
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}

/**
 * Analyzes the given file and updates the climate_info structs as necessary.
 * @param file The file to analyze.
 * @param states An array of pointers to climate_info structs.
 * @param num_states The number of elements in the states array.
 */
void
analyze_file (FILE *file, struct climate_info **states, int num_states)
{
  const int line_sz = 100;
  char line[line_sz];
  while (fgets (line, line_sz, file) != NULL)
    {
      char *token;
      char *code;
      /* Tokenize the line */
      token = strtok (line, "\t"); // state code
      code = token;
      climate *info = get_climate (states, num_states, code);
      update_climate (info);
    }
}

/**
 * Prints a report of climate information for each state in the given array of
 * climate_info structs.
 *
 * @param states An array of pointers to climate_info structs.
 * @param num_states The number of elements in the states array.
 */
void
print_report (struct climate_info *states[], int num_states)
{
  printf ("States found:\n");
  int i;
  /* Print out the summary for each state.*/
  for (i = 0; i < num_states; ++i)
    {
      if (states[i] != NULL)
        {
          climate *info = states[i];
          double average_temp = info->sum_temp / info->num_records;
          double average_humidity = info->sum_humidity / info->num_records;
          double average_cloud = info->sum_cloud / info->num_records;

          // Convert max/min temp timestamps to human-readable format
          char max_temp_timestamp_str[26], min_temp_timestamp_str[26];
          time_t max_temp_timestamp = info->max_temp_timestamp;
          time_t min_temp_timestamp = info->min_temp_timestamp;
          strcpy (max_temp_timestamp_str, ctime (&max_temp_timestamp));
          strcpy (min_temp_timestamp_str, ctime (&min_temp_timestamp));

          printf ("-- State: %s --\n", info->code);
          printf ("Number of Records: %lu\n", info->num_records);
          printf ("Average Humidity: %.1f%%\n", average_humidity);
          printf ("Average Temperature: %.1fF\n", average_temp);
          printf ("Max Temperature: %.1fF\n", info->max_temp);
          printf ("Max Temperature on: %s", max_temp_timestamp_str);
          printf ("Min Temperature: %.1fF\n", info->min_temp);
          printf ("Min Temperature on: %s", min_temp_timestamp_str);
          printf ("Lightning Strikes: %lu\n", info->num_lightning);
          printf ("Records with Snow Cover: %lu\n", info->num_snow);
          printf ("Average Cloud Cover: %.1f%%\n", average_cloud);
          printf ("\n");
        }
    }
  printf ("\n");
}

/**
 * Frees the memory allocated for each climate struct in the given array.
 *
 * @param states An array of pointers to climate_info structs.
 * @param num_states The number of elements in the states array.
 */
void
free_states (climate *states[], int num_states)
{
  for (int i = 0; i < num_states; ++i)
    {
      if (states[i] != NULL)
        {
          free (states[i]);
        }
    }
}

/**
 * Initializes a climate struct with the given code and adds it to the states
 * array.
 *
 * @param code The code for the climate.
 * @param states An array of climate structs to search through.
 * @param num_states The number of elements in the states array.
 * @return A pointer to the initialized climate struct.
 */
climate *
init_climate (climate *states[], int num_states, char *code)
{
  /* If our states array doesn't have a climate_info entry for this state, then
   * we need to allocate memory for it and put it in the next open place in the
   * array. Otherwise, we reuse the existing entry. */
  climate *info = calloc (1, sizeof (climate));
  if (info == NULL)
    {
      printf ("Memory allocation failed\n");
      free_states (states, num_states);
      exit (EXIT_FAILURE);
    }
  strcpy (info->code, code);
  info->max_temp = -DBL_MAX;
  info->min_temp = DBL_MAX;
  for (int i = 0; i < num_states; ++i)
    {
      if (states[i] == NULL)
        {
          states[i] = info;
          break;
        }
    }
  return info;
}

/**
 * Returns a pointer to the climate struct with the given code. If the climate
 * struct doesn't exist, it is initialized and added to the states array.
 * Otherwise, the existing climate struct is returned.
 *
 * @param states An array of climate structs to search through.
 * @param num_states The number of elements in the states array.
 * @param code The code to search for in the code field of the climate structs.
 *
 * @return A pointer to the climate struct with the given code.
 */
climate *
get_climate (climate *states[], int num_states, char *code)
{
  /* Determine what state the line if for. This will be the state code, stored
   * as our first token.*/
  for (int i = 0; i < num_states; ++i)
    {
      if (states[i] != NULL)
        {
          if (strcmp (states[i]->code, code) == 0)
            {
              return states[i];
            }
        }
    }
  climate *info = init_climate (states, num_states, code);
  return info;
}

/**
 * Updates the given climate struct with the data from the given line.
 *
 * @param info Pointer to the climate struct to be updated.
 */
void
update_climate (climate *info)
{
  char *token;
  unsigned long timestamp;
  int humidity, snow, cloud, lightning;
  double temp_kelvin, temp_fahrenheit;

  token = strtok (NULL, "\t"); // timestamp
  timestamp = strtoul (token, NULL, 10);
  timestamp /= 1000;           // convert to seconds
  strtok (NULL, "\t");         // geolocation
  token = strtok (NULL, "\t"); // humidity
  humidity = atoi (token);
  token = strtok (NULL, "\t"); // snow cover
  snow = atoi (token);
  token = strtok (NULL, "\t"); // cloud cover
  cloud = atoi (token);
  token = strtok (NULL, "\t"); // lightning strikes
  lightning = atoi (token);
  strtok (NULL, "\t");         // pressure
  token = strtok (NULL, "\t"); // surface temperature
  temp_kelvin = strtod (token, NULL);
  temp_fahrenheit = temp_kelvin * 1.8 - 459.67; // convert to Fahrenheit
  info->num_records++;
  info->sum_temp += temp_fahrenheit;
  info->sum_humidity += humidity;
  if (temp_fahrenheit > info->max_temp)
    {
      info->max_temp = temp_fahrenheit;
      info->max_temp_timestamp = timestamp;
    }
  if (temp_fahrenheit < info->min_temp)
    {
      info->min_temp = temp_fahrenheit;
      info->min_temp_timestamp = timestamp;
    }
  info->num_lightning += lightning;
  info->num_snow += snow;
  info->sum_cloud += cloud;
}
