/*
 * stage2.c
 * Problem 0301: A fight with oneself - Mentor Matching System
 * ANSI C - GNU Coding Standards
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAINEES 20
#define MAX_MENTORS 8
#define MAX_NAME_LEN 50

// ---------- STRUCT DEFINITIONS ----------
typedef struct
{
  char nickname[MAX_NAME_LEN];
  int ascii_sum;
  int ability;
} Trainee;

typedef struct
{
  int id; // Unique ID from 1 to 8
  char name[MAX_NAME_LEN];
  int mentee_number;
} Mentor;

// ---------- GLOBAL ARRAYS ----------
Trainee trainees[MAX_TRAINEES];
int trainee_count = 0;

Mentor mentors[MAX_MENTORS];
int mentor_count = 0;

// ---------- FUNCTION DECLARATIONS ----------
int parseIntMember(char *nickname);
int getRandomAbility();
void initializeTrainees();
void inputMentors();
void matchMentoring();
void printMentoringResults();

// ---------- FUNCTION DEFINITIONS ----------
int parseIntMember(char *nickname)
{
  int sum = 0;
  for (int i = 0; nickname[i] != '\0'; i++)
  {
    sum += (int)nickname[i];
  }
  return sum;
}

int getRandomAbility()
{
  return (rand() % 901) + 100; // 100 to 1000
}

void initializeTrainees()
{
  char *sampleNicknames[] = {
      "Nova", "Astra", "Orion", "Luna", "Vega",
      "Zion", "Rhea", "Lyra", "Sol", "Echo",
      "Neo", "Iris", "Draco", "Elio", "Kai"};

  trainee_count = sizeof(sampleNicknames) / sizeof(sampleNicknames[0]);

  for (int i = 0; i < trainee_count; i++)
  {
    strcpy(trainees[i].nickname, sampleNicknames[i]);
    trainees[i].ascii_sum = parseIntMember(trainees[i].nickname);
    trainees[i].ability = getRandomAbility();
  }
}

void inputMentors()
{
  printf("Enter up to 8 mentors (name only):\n");
  mentor_count = 0;

  for (int i = 0; i < MAX_MENTORS; i++)
  {
    char name[MAX_NAME_LEN];
    printf("Mentor %d name (or 'end' to stop): ", i + 1);
    scanf("%s", name);

    if (strcmp(name, "end") == 0)
      break;

    mentors[mentor_count].id = i + 1;
    strcpy(mentors[mentor_count].name, name);
    mentors[mentor_count].mentee_number = -1; // initially unassigned
    mentor_count++;
  }
}

void matchMentoring()
{
  for (int i = 0; i < trainee_count; i++)
  {
    int mentor_id = (i % MAX_MENTORS) + 1;
    for (int j = 0; j < mentor_count; j++)
    {
      if (mentors[j].id == mentor_id)
      {
        mentors[j].mentee_number = i;
        break;
      }
    }
  }
}

void printMentoringResults()
{
  printf("\n--- Mentoring Results ---\n");
  for (int i = 0; i < mentor_count; i++)
  {
    if (mentors[i].mentee_number >= 0)
    {
      int mentee_index = mentors[i].mentee_number;
      printf("Trainee #%d (%s) -> Mentor ID %d (%s)\n",
             mentee_index + 1,
             trainees[mentee_index].nickname,
             mentors[i].id,
             mentors[i].name);
    }
  }
}

// ---------- MAIN EXECUTION ----------
int main()
{
  srand((unsigned int)time(NULL));

  initializeTrainees();
  inputMentors();
  matchMentoring();
  printMentoringResults();

  return 0;
}
