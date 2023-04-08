#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFFER_SIZE 1024

/**
 * check_elf_file - Check if file is an ELF file
 *
 * @header: Pointer to the ELF header
 *
 * Return: 1 if ELF file, otherwise 0
 */
int check_elf_file(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
	    header->e_ident[EI_MAG1] != ELFMAG1 ||
	    header->e_ident[EI_MAG2] != ELFMAG2 ||
	    header->e_ident[EI_MAG3] != ELFMAG3)
		return (0);

	return (1);
}

/**
 * print_elf_header - Display the information contained in the ELF header
 *
 * @header: Pointer to the ELF header
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("  Class:                             %s\n",
	       header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
	       header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
	       header->e_ident[EI_CLASS] == ELFCLASSNONE ? "Invalid class" :
	       "Unknown class");

	printf("  Data:                              %s\n",
	       header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
	       header->e_ident[EI_DATA] == ELFDATANONE ? "Invalid data encoding" :
	       "Unknown data encoding");

	printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            %s\n",
	       header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
	       header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
	       header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
	       header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
	       header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
	       header->e_ident[EI_OSABI] == ELFOSABI_AIX ? "UNIX - AIX" :
	       header->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
	       header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
	       header->e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
	       header->e_ident[EI_OSABI] == ELFOSABI_MODESTO ? "Novell - Modesto" :
	       header->e_ident[EI_OSABI] == ELFOSABI_OPENBSD ? "UNIX - OpenBSD" :
	       header->e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM"
