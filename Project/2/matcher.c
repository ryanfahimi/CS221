/**
 * You can modify this file.
 */

#include "matcher.h"

/* Named constants for better clarity */
#define TRUE 1
#define FALSE 0
#define STEP_OVER_CHAR 2

/**
 * Your helper functions can go below this line
 */

/**
 * Determines if the given character is one of the special characters
 * recognized by our pattern matcher.
 *
 * @param c The character to check.
 * @return TRUE if the character is special, otherwise FALSE.
 */
int
is_special_char (char c)
{
  return c == '.' || c == '+' || c == '?' || c == '\\';
}

/**
 * Handles the pattern where a character can be optional.
 * Increments the pointers appropriately based on the pattern.
 *
 * @param partial_line The current position in the input line.
 * @param pattern The current position in the pattern string.
 */
void
handle_question_mark (char **partial_line, char **pattern)
{
  if (*(*pattern) == *(*partial_line) || *(*pattern) == '.')
    {
      (*partial_line)++;
    }
  (*pattern) += STEP_OVER_CHAR;
}

/**
 * Handles the pattern where a character can be repeated one or more times.
 * Increments the pointers as needed.
 *
 * @param partial_line The current position in the input line.
 * @param pattern The current position in the pattern string.
 */
void
handle_plus_sign (char **partial_line, char **pattern)
{
  while (*(*partial_line)
         && (*(*partial_line) == *(*pattern) || *(*pattern) == '.'))
    {
      (*partial_line)++;
    }
  (*pattern) += STEP_OVER_CHAR;
}

/**
 * Your helper functions can go above this line
 */

/**
 * Determines if the provided partial_line matches the given pattern
 * starting from the first character of the partial_line.
 *
 * @param partial_line The line segment to be matched.
 * @param pattern The pattern string.
 * @return TRUE if there's a match, otherwise FALSE.
 */
int
matches_leading (char *partial_line, char *pattern)
{
  while (*partial_line && *pattern)
    {
      switch (*pattern)
        {
        case '\\':
          pattern++;
          if (!*pattern || *pattern != *partial_line)
            {
              return FALSE;
            }
          partial_line++;
          pattern++;
          break;
        case '.':
          partial_line++;
          pattern++;
          break;
        default:
          if (*(pattern + 1) && pattern[1] == '?')
            {
              handle_question_mark (&partial_line, &pattern);
            }
          else if (*(pattern + 1) && pattern[1] == '+')
            {
              if (*pattern != '.' && *pattern != *partial_line)
                {
                  return FALSE;
                }
              handle_plus_sign (&partial_line, &pattern);
            }
          else if (*pattern != *partial_line)
            {
              return FALSE;
            }
          else
            {
              partial_line++;
              pattern++;
            }
          break;
        }
    }

  /* Skip any remaining optional characters in the pattern */
  while (*(pattern + 1) && (pattern[1] == '?' && !is_special_char (*pattern)))
    {
      pattern += STEP_OVER_CHAR;
    }

  return !(*pattern); // Return TRUE if we've matched the whole pattern
}

/**
 * Recursively checks if the given line matches the pattern.
 * It tries to find a match from the beginning of the line, and
 * if not found, it moves one character over and tries again.
 *
 * @param line The input line.
 * @param pattern The pattern string.
 * @return TRUE if there's a match anywhere in the line, otherwise FALSE.
 */
int
rgrep_matches (char *line, char *pattern)
{
  if (!*line)
    {
      return FALSE;
    }
  if (matches_leading (line, pattern))
    {
      return TRUE;
    }
  return rgrep_matches (line + 1, pattern);
}