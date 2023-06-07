#include "minishell.h"

// env de istediğin bölümün adını yazıyorsun sadece, "PATH" gibi. Sana o arrayin adresini döndürüyor


char    *cut_helper(const char *str)
{
    int     i;
    char    *rstr;

    i = ft_strlen(str) - 1;
    rstr = (char *)malloc(i + 2);
    if (str[i] == '/')
        i--;
    while (i >= 0 && str[i] != '/')
        i--;
    ft_strlcpy(rstr, str, i + 1);
	if (ft_strlen(rstr) < 2)
		ft_strlcpy(rstr, "/", 2);
    printf("---> rstr: %s\n", rstr); //? yeni konum
    return (rstr);
}



int	cd_func(int i)
{
    char	*hm_test = getenv("HOME");
	char	*home;
    char	path[1024];
    int     a;
    char	*p;

	home = find_in_env("PWD") + 4;
	printf("test find in env: %s\n", home);
    if (getcwd(path, sizeof(path)) == NULL)
        printf("---> Path error\n");
    else if (strequal(g_var.str[i], "pwd"))
        printf("%s\n", path);
    else if (strequal(g_var.str[i + 1], ".."))
    {
		printf("---> path %s\n", path);
        p = cut_helper(path);
    	a = chdir(p);
    }
	else if (g_var.str[i + 1])
	{
		if (strequal(g_var.str[i + 1], "~")) // ana dizine çıkma ve ana dizinden farklı bir dizine ulaşmak için
		{
			if (ft_strlen(g_var.str[i + 1]) > 1)
			{
				p = ft_strjoin(home, g_var.str[i + 1] + 1);
				a = chdir(p);

			}
			else
			{
				a = chdir(home);
			}
		}
		else // cd ile, ileri gitme bölümü
		{
			if (ft_strlen(path) > 1)
				p = ft_strjoin(path, "/");
			else
				p = 0;
			printf("p: %s\n", p);
			getchar();
			p = ft_strjoin(p, g_var.str[i + 1]);
			printf("yeni dizin: %s\n", p);
			a = chdir(p);
		}
	}
	else
		chdir(home);
	printf("** cd işlem sonucu: %s\n", getcwd(path, sizeof(path)));
	
	if (g_var.pwd_new)
	{	
		free(g_var.pwd_new);
		g_var.pwd_new = NULL;
	}
	g_var.pwd_new = ft_strjoin("PWD=", p);
	printf("pwd_new: %s\n", g_var.pwd_new);
	free(p);
    return 0;
}
