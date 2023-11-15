/**
 * You can modify this file.
 */

#include "matcher.h"

/* Named constants for better clarity */
#define TRUE 1
#define FALSE 0
#define STEP_OVER_CHAR 2
#define PERIOD '.'
#define PLUS_SIGN '+'
#define QUESTION_MARK '?'
#define BACKSLASH '\\'
#define NEWLINE '\n'
#define NULL_TERMINATOR '\0'

/**
 * Your helper functions can go below this line
 */

/**
 * Handles the pattern where a character can be optional.
 * Increments the pointers appropriately based on the pattern.
 *
 * @param partial_line The current position in the input line.
 * @param pattern The current position in the pattern string.
 */
void
handle_optional_char (char **partial_line, char **pattern)
{
  if (**partial_line == **pattern)
    {
      (*partial_line)++;
    }
  *pattern += STEP_OVER_CHAR;
}

/**
 * Handles the pattern where a character can be repeated one or more times.
 * Increments the pointers as needed.
 *
 * @param partial_line The current position in the input line.
 * @param pattern The current position in the pattern string.
 */
void
handle_repeatable_char (char **partial_line, char **pattern)
{
  while (**partial_line && (**partial_line == **pattern))
    {
      (*partial_line)++;
    }
  *pattern += STEP_OVER_CHAR;
}

/**
 * Skips any optional characters in the pattern.
 * Increments the pattern pointer as needed.
 *
 * @param pattern The current position in the pattern string.
 */
void
skip_optional_chars (char **pattern)
{
  while (**pattern && *(*pattern + 1) && *(*pattern + 1) == QUESTION_MARK
         && **pattern != BACKSLASH)
    {
      *pattern += STEP_OVER_CHAR;
    }
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
      if (*partial_line == NEWLINE)
        {
          partial_line++; // Skip newline characters
          continue;
        }
      else if (*pattern == BACKSLASH)
        {
          pattern++;
        }
      else if (*pattern == PERIOD)
        {
          partial_line++;
          pattern++;
          continue;
        }
      if (pattern[1] == QUESTION_MARK)
        {
          handle_optional_char (&partial_line, &pattern);
        }
      else if (*pattern != *partial_line)
        {
          return FALSE;
        }
      else if (pattern[1] == PLUS_SIGN)
        {
          handle_repeatable_char (&partial_line, &pattern);
        }
      else
        {
          partial_line++;
          pattern++;
        }
    }

  /* Skip any remaining optional characters in the pattern */
  skip_optional_chars (&pattern);

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