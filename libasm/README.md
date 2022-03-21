This project is written in x64 assembly
The goal is to re-write simple C functions in assembly.

## Rules
* You must write 64 bits ASM. Beware of the "calling convention".
* You can’t do inline ASM, you must do ’.s’ files.
* You must compile your assembly code with nasm.
* You must use the Intel syntax, not the AT&T.
* You must check for errors during syscalls and properly set them when needed
* Your code must set the variable errno properly. For that, you are allowed to call the extern ___error.

## Functions 
* ft_strlen (man 3 strlen)
* ft_strcpy (man 3 strcpy)
* ft_strcmp (man 3 strcmp)
* ft_write (man 2 write)
* ft_read (man 2 read)
* ft_strdup (man 3 strdup, you can call to malloc)
* ft_atoi_base (like the one in the piscine)
* ft_list_push_front (like the one in the piscine)
* ft_list_size (like the one in the piscine)
* ft_list_sort (like the one in the piscine)
* ft_list_remove_if (like the one in the piscine)
