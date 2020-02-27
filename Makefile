# Assemble all files here

all: assembly c_code linker_bin cleanup execute_bin

assembly:
	@nasm -f elf32 kernel/boot.asm -o kernel/boot.o

c_code:
	@gcc -m32 -c kernel/main.c -o kernel/main.o

linker_bin:
	@rm -fr boot/bin/os.bin
	@ld -m elf_i386 -T kernel/linker.ld -o boot/bin/os.bin kernel/boot.o kernel/main.o

cleanup:
	@rm -fr kernel/*.o

generate_iso:
	@grub-mkrescue -o dist/duox2.iso boot

execute_iso:
	@qemu-system-i386 dist/duox2.iso

execute_bin:
	@qemu-system-i386 -kernel boot/bin/os.bin