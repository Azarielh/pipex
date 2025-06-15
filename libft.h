/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:19:21 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/01 23:04:42 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file libft.h
 * @brief Header file for the libft library.
 *
 * This file contains the function prototypes and type definitions for the
 * libft library, which provides a collection of utility functions for
 * string manipulation, memory management, and linked list operations.
 *
 * @author jlacaze-
 * @date Created on: 2024/11/14
 * @date Updated on: 2025/02/17
 */

 #ifndef LIBFT_H
 #define LIBFT_H
 
 #include <stdlib.h>
 #include <string.h>
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               STRUCTURE
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 
 /**
  * @struct s_list
  * @brief A structure representing a node in a linked list.
  *
  * @var s_list::content
  * The content of the node.
  * @var s_list::next
  * A pointer to the next node in the list.
  */
 typedef struct s_list
 {
	 void *content;
	 struct s_list *next;
 } t_list;
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               BOOLEAN
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief This is a boolean. Checks if the given character is alphanumeric.
  *
  * @param c The character to check.
  * @return Non-zero if the character is alphanumeric, zero otherwise.
  */
 int ft_isalnum(int c);
 
 /**
  * @brief This is a boolean. Checks if the given character is alphabetic.
  *
  * @param c The character to check.
  * @return Non-zero if the character is alphabetic, zero otherwise.
  */
 int ft_isalpha(int c);
 
 /**
  * @brief This is a boolean. Checks if the given character is an ASCII character.
  *
  * @param c The character to check.
  * @return Non-zero if the character is an ASCII character, zero otherwise.
  */
 int ft_isascii(int c);
 
 /**
  * @brief This is a boolean. Checks if the given character is a digit.
  *
  * @param c The character to check.
  * @return Non-zero if the character is a digit, zero otherwise.
  */
 int ft_isdigit(int c);
 
 /**
  * @brief This is a boolean. Checks if the given character is printable.
  *
  * @param c The character to check.
  *
  * @return Non-zero if the character is printable, zero otherwise.
  */
 int ft_isprint(int c);
 
 /**
  * @brief This is a boolean. Checks if the given character is one of the characters in the given string.
  *
  * @param c The character to check.
  * @param str The string to check against.
  *
  * @return Non-zero if the character is in the string, zero otherwise.
  */
 int ft_are_u_1_of_u(char c, char *str);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               CONVERTION
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief Converts a string to an integer.
  *
  * @param str The string to convert.
  * @return The integer value of the string.
  */
 int ft_atoi(const char *str);
 
 /**
  @brief Converts an integer to a null-terminated string.
  *
  * @param n The integer to convert.
  * @return A pointer to the string representation of the integer, or NULL if memory allocation fails.
  */
 char *ft_itoa(int n);
 
 /**
  * @brief Converts the given character to lowercase.
  *
  * @param c The character to convert.
  *
  * @return The lowercase equivalent of the character, or the character itself if it is not alphabetic.
  */
 int ft_tolower(int c);
 
 /**
  * @brief Converts the given character to uppercase.
  *
  * @param c The character to convert.
  *
  * @return The uppercase equivalent of the character, or the character itself if it is not alphabetic.
  */
 int ft_toupper(int c);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               FINDER
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief Locates the first occurrence of c in the string str.
  *
  * @param str The string to search.
  * @param c The character to locate.
  * @return A pointer to the first occurrence of c in str, or NULL if c is not found.
  */
 char *ft_strchr(const char *str, int c);
 
 /**
  * @brief Locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched.
  *
  * @param big The string to search.
  * @param little The substring to locate.
  * @param len The maximum number of characters to search.
  * @return A pointer to the first occurrence of little in big, or NULL if little is not found.
  */
 char *ft_strnstr(const char *big, const char *little, size_t len);
 
 /**
  * @brief Locates the last occurrence of c in the string str.
  *
  * @param str The string to search.
  * @param c The character to locate.
  * @return A pointer to the last occurrence of c in str, or NULL if c is not found.
  */
 char *ft_strrchr(const char *str, int c);
 
 /**
  * @brief Allocates and returns a substring from the string s.
  *
  * @param s The string to create the substring from.
  * @param start The start index of the substring.
  * @param len The length of the substring.
  * @return A pointer to the substring, or NULL if memory allocation fails.
  */
 char *ft_substr(char const *s, unsigned int start, size_t len);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               GNL
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief Read any text from any file descriptors. It does so one line at a time. It mange many fd at once but doet not bother with open or close. You will have to deal with that on your own elsewhere.
  *
  * @param fd File descriptor you want to deal with
  *
  * @return The return value is the entire line it reads. From the top left to next \\n it founds.
  */
 char *get_next_line(int fd);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               LIST
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief Adds the element new_elem at the beginning of the list **lst.
  *
  * @param lst The address of a pointer to the first link of a list.
  * @param new_elem The address of a pointer to the element to be added to the list.
  */
 void ft_lstadd_front(t_list **lst, t_list *new_elem);
 
 /**
  * @brief Adds the element new_elem at the end of the list **lst
  *
  * @param lst The address of a pointer to the first link of a list.
  * @param new_elem The address of a pointer to the element to be added to the list.
  */
 void ft_lstadd_back(t_list **lst, t_list *new_elem);
 
 /**
  * @brief Takes as a parameter an element and frees the memory of the element’s content using the function del given as a parameter, then frees the element.
  *
  * @param lst The element to free.
  * @param del The function to delete the content of the element.
  */
 void ft_lstdelone(t_list *lst, void (*del)(void *));
 
 /**
  * @brief Deletes and frees the given element and every successor of that element, using the function del and free.
  *
  * @param lst The address of a pointer to an element.
  * @param del The function to delete the content of the element.
  */
 void ft_lstclear(t_list **lst, void (*del)(void *));
 
 /**
  * @brief Iterates the list lst and applies the function f to the content of each element.
  *
  * @param lst The address of a pointer to an element.
  * @param f The function to apply to each element.
  */
 void ft_lstiter(t_list *lst, void (*f)(void *));
 
 /**
  * @brief Allocates and returns a new element. The variable content is initialized with the value of the parameter content. The variable next is initialized to NULL.
  *
  * @param content The content to create the new element with.
  * @return The new element.
  */
 t_list *ft_lstnew(void *content);
 
 /**
  * @brief Returns the last element of the list.
  *
  * @param lst The beginning of the list.
  * @return The last element of the list.
  */
 t_list *ft_lstlast(t_list *lst);
 
 /**
  * @brief Iterates the list lst and applies the function f to the content of each element. Creates a new list resulting from the successive applications of the function f. The del function is used to delete the content of an element if needed.
  *
  * @param lst The address of a pointer to an element.
  * @param f The function to apply to each element.
  * @param del The function to delete the content of an element if needed.
  * @return The new list, or NULL if memory allocation fails.
  */
 t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
 
 /**
  * @brief Counts the number of elements in a list.
  *
  * @param lst The beginning of the list.
  * @return The number of elements in the list.
  */
 int ft_lstsize(t_list *lst);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               MEMORY
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief Sets the first n bytes of the block of memory pointed by s to zero.
  *
  * @param s The block of memory to set.
  * @param n The number of bytes to set to zero.
  */
 void ft_bzero(void *s, size_t n);
 
 /**
  * @brief Fills the first n bytes of the memory area pointed to by s with the constant byte c.
  *
  * @param s The memory area to fill.
  * @param c The byte to fill with.
  * @param n The number of bytes to fill.
  * @return A pointer to the memory area s.
  */
 void *ft_memset(void *s, int c, size_t n);
 
 /**
  * @brief Copies n bytes from memory area src to memory area dest. The memory areas may overlap.
  *
  * @param dest The destination memory area.
  * @param src The source memory area.
  * @param n The number of bytes to copy.
  * @return A pointer to the destination memory area dest.
  */
 void *ft_memmove(void *dest, const void *src, size_t n);
 
 /**
  * @brief Scans the initial n bytes of the memory area pointed to by str for the first instance of c.
  *
  * @param str The memory area to scan.
  * @param c The byte to search for.
  * @param n The number of bytes to scan.
  * @return A pointer to the matching byte, or NULL if the byte is not found.
  */
 void *ft_memchr(const void *str, int c, size_t n);
 
 /**
  * @brief Copies n bytes from memory area src to memory area dest. The memory areas must not overlap.
  *
  * @param dest The destination memory area.
  * @param src The source memory area.
  * @param n The number of bytes to copy.
  * @return A pointer to the destination memory area dest.
  */
 void *ft_memcpy(void *dest, const void *src, size_t n);
 
 /**
  * @brief Compares two blocks of memory.
  *
  * @param s1 The first block of memory to compare.
  * @param s2 The second block of memory to compare.
  * @param n The number of bytes to compare.
  * @return An integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2.
  */
 int ft_memcmp(const void *s1, const void *s2, size_t n);
 
 /**
  * @brief Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero.
  *
  * @param nmemb The number of elements.
  * @param size The size of each element.
  * @return A pointer to the allocated memory, or NULL if memory allocation fails.
  */
 void *ft_calloc(size_t nmemb, size_t size);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               OUTPUT
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief A formatted output conversion.
  *
  * @param str The format string.
  * @param ... The values to format.
  * @return The number of characters printed.
  */
 int ft_printf(const char *str, ...);
 
 /**
  * @brief Writes the character c to the given file descriptor.
  *
  * @param c The character to write.
  * @param fd The file descriptor to write to.
  * @return The number of characters written.
  */
 size_t ft_putchar_fd(char c, int fd);
 
 /**
  * @brief Writes the string str to the given file descriptor.
  *
  * @param str The string to write.
  * @param fd The file descriptor to write to.
  * @return The number of characters written.
  */
 size_t ft_putstr_fd(char *str, int fd);
 
 /**
  * @brief Writes the integer n to the given file descriptor.
  *
  * @param n The integer to write.
  * @param fd The file descriptor to write to.
  * @return The number of characters written.
  */
 size_t ft_putnbr_fd(int n, int fd);
 
 /**
  * @brief Writes the decimal representation of the unsigned long nb.
  *
  * @param nb The number to write.
  * @return The number of characters written.
  */
 long long ft_putnbr_deci(unsigned long nb);
 
 /**
  * @brief Writes the hexadecimal representation of the unsigned long nb.
  *
  * @param nb The number to write.
  * @param caps If non-zero, use uppercase letters for the hexadecimal digits.
  * @return The number of characters written.
  */
 unsigned long ft_puthex(unsigned long nb, char caps);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               STR ANALYSIS
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief Compares up to n characters of two strings.
  *
  * @param str1 The first string to compare.
  * @param str2 The second string to compare.
  * @param n The maximum number of characters to compare.
  *
  * @return An integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than, to match, or be greater than str2.
  */
 int ft_strncmp(const char *str1, const char *str2, size_t n);
 
 /**
  * @brief Calculates the length of a string.
  *
  * @param str The string to calculate the length of.
  * @return The length of the string.
  */
 int ft_strlen(const char *str);
 
 /*
 _____________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               STR MANIPULATION
 *
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
 /**
  * @brief Writes the string s to the given file descriptor, followed by a newline.
  *
  * @param s The string to write.
  * @param fd The file descriptor to write to.
  */
 void ft_putendl_fd(char *s, int fd);
 
 /**
  * @brief Splits the string str into an array of strings using the character c as a delimiter.
  *
  * @param str The string to split.
  * @param c The delimiter character.
  * @return A pointer to the array of strings, or NULL if memory allocation fails.
  */
 char **ft_split(char const *str, char c);
 
 /**
  * @brief Duplicates the string str.
  *
  * @param str The string to duplicate.
  * @return A pointer to the duplicated string, or NULL if memory allocation fails.
  */
 char *ft_strdup(const char *str);
 
 /**
  * @brief Applies the function f to each character of the string str, passing its index as the first argument.
  *
  * @param str The string to iterate over.
  * @param f The function to apply to each character.
  */
 void ft_striteri(char *str, void (*f)(unsigned int, char *));
 
 /**
  * @brief Allocates and returns a new string, which is the result of the concatenation of s1 and s2.
  *
  * @param s1 The first string.
  * @param s2 The second string.
  * @return A pointer to the concatenated string, or NULL if memory allocation fails.
  */
 char *ft_strjoin(char const *s1, char const *s2);
 
 /**
  * @brief Appends the string src to the end of dest, up to size - strlen(dest) - 1 characters.
  *
  * @param dest The destination buffer.
  * @param src The source string.
  * @param size The size of the destination buffer.
  * @return The total length of the string it tried to create.
  */
 size_t ft_strlcat(char *dest, const char *src, size_t size);
 
 /**
  * @brief Copies up to size - 1 characters from the string src to dest, NUL-terminating the result.
  *
  * @param dest The destination buffer.
  * @param src The source string.
  * @param size The size of the destination buffer.
  * @return The total length of the string it tried to create.
  */
 size_t ft_strlcpy(char *dest, const char *src, size_t size);
 
 /**
  * @brief Applies the function f to each character of the string s to create a new string resulting from successive applications of f.
  *
  * @param s The string to map.
  * @param f The function to apply to each character.
  * @return A pointer to the new string, or NULL if memory allocation fails.
  */
 char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
 
 /**
  * @brief Allocates and returns a copy of s1 with the characters specified in set removed from the beginning and the end of the string.
  *
  * @param s1 The string to trim.
  * @param set The set of characters to remove.
  * @return A pointer to the trimmed string, or NULL if memory allocation fails.
  */
 char *ft_strtrim(char const *s1, char const *set);
 
 #endif