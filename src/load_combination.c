#include	"load_combination.h"

static int	check_password(char *buffer, int *combination)
{
  int		i;

  for (i = 0; i < 9; ++i)
    {
      if (buffer[i] < '0' || buffer[i] > '9')
	{
	  puts("Error : The password file must contain only numbers");
	  return (0);
	}
      combination[i] = buffer[i] - '0';
    }
  return (1);
}

int	*load_combination()
{
  int	*combination;
  char	buffer[9];
  int	fd;

  if ((combination = malloc(9 * sizeof(int))) == NULL)
    {
      puts("Error : Failed to allocate the combination tab");
      return (NULL);
    }
  if ((fd = open(PASS_FILE, O_RDONLY)) == -1)
    {
      puts("Error : Failed to open the password file");
      return (NULL);
    }
  if (read(fd, buffer, 9) != 9)
    {
      puts("Error : The password file must contain 9 numbers");
      return (NULL);
    }
  if (!check_password(buffer, combination))
    return (NULL);
  return (combination);
}
