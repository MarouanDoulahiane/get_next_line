/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoulahi <mdoulahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:14:40 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/11/04 17:27:59 by mdoulahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
// void checkMemoryLeaks() {
//     // Function to check for memory leaks
//     // This will be called at program exit
//     // You can run memory checking tools here
//     printf("Checking for memory leaks...\n");
// }

void f() {
    // Register the function to check for memory leaks at exit
   system("leaks  main");
}


int main(void) {
    char *line;
    int fd;
    atexit(f); // join?
    // Register the function to check for memory leaks at exit
// char *res = malloc(3121);
    // Open the file for reading (make sure "file.txt" exists)
 
    fd = open("file.txt", O_RDONLY);
    // if (fd == -1) {
    //     perror("open");
    //     return 1;
    // }
    // printf("start!!\n");
    while ((line = get_next_line(1)))
    {
        printf("%s", line);
        fflush(stdout);
        free(line);
    }
    close(fd);
    // while(1);
    return 0;
}