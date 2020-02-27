# Assemble all files here

KERNEL_PATH = src/kernel
LIBRARIES_PATH = src/app/libraries
MODULES_PATH = src/app/modules
BOOT_PATH = boot/bin
STATIC_PATH = static

all: assembly libraries c_code linker_bin cleanup execute_bin

assembly:
	@nasm -f elf32 $(KERNEL_PATH)/boot.asm -o $(STATIC_PATH)/boot.o

c_code:
	@gcc -m32 -c $(KERNEL_PATH)/main.c -o $(STATIC_PATH)/main.o \
	-L$(STATIC_PATH)/bootstraplib -lbootstraplib

libraries:
	@gcc -m32 -fPIC -c $(MODULES_PATH)/bootstrap.c -o $(STATIC_PATH)/bootstrap.o
	@gcc -m32 -shared -o $(STATIC_PATH)/bootstraplib.so $(STATIC_PATH)/bootstrap.o 
	
linker_bin:
	@rm -fr boot/bin/os.bin
	@ld -m elf_i386 -T $(KERNEL_PATH)/linker.ld -o boot/bin/os.bin $(STATIC_PATH)/*.o

cleanup:
	@rm -fr $(KERNEL_PATH)/*.o
	@rm -fr $(LIBRARIES_PATH)/*.o
	@rm -fr $(MODULES_PATH)/*.o
	@rm -fr $(STATIC_PATH)/*.o $(STATIC_PATH)/*.so


generate_iso:
	@grub-mkrescue -o dist/duox2.iso boot

execute_iso:
	@qemu-system-i386 dist/duox2.iso

execute_bin:
	@qemu-system-i386 -kernel boot/bin/os.bin