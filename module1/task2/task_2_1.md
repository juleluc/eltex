## Задания. Раздел 1
Лог работы – команды и результаты в записать в файл practice2_part1.log  

### 1.Создайте на сервере для 1 практики ключ ssh при помощи программы ssh-keygen  
***Используем команду ssh-keygen для создания ключа.***  
        eltex-pg2-v26@eltext:~$ ssh-keygen  
### 2.Скопируйте созданный ключ на сервер для 2 практики для пользователя root при помощи программы ssh-copy-id  

    eltex-pg2-v26@eltext:~$ ssh-copy-id root@172.16.9.226
    /usr/bin/ssh-copy-id: INFO: Source of key(s) to be installed: "/home/eltex-pg2-v26/.ssh/id_rsa.pub"
    /usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
    /usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
    root@172.16.9.226's password:
    Number of key(s) added: 1
    Now try logging into the machine, with:   "ssh 'root@172.16.9.226'"
    and check to make sure that only the key(s) you wanted were added.
    eltex-pg2-v26@eltext:~$

### 3.Подключитесь к серверу для 2 практики под пользователем root и сравните содержимое файла открытого ключа на сервере 1 ~/.ssh/*.pub и файла ~/.ssh/authorized_keys на сервере для 2 практики, а так же права доступа для каждого из файлов Все последующие пункты – для сервера 2 практики  
***Содержимое файла ключа на сервере 2.***  

    root@eltex-practice2-pg2-v26:~# cat .ssh/authorized_keys
    ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCjKfL26WWGWFAqW7ih+TtVK0sHPpJn7J01Q1PJE0zJIG7lvcTEwRojH5ehcZ6C5LlNtzDeOcgQDKvIlfoX/H/KllIC5AFgPWsSAfIG59MMjYQV0X6dwuqhgwM6otRox/gLjIBC9GCYuG5YKGdLrQjxRGKKD6A5UTADHgY4f768u50zxWQQ2RMBUoqBcUSX0wmkxwZ7NNUbJWE8RB8SXLYXjSs7WrC9L1dYNRhG2ANiCFIJr7NFpxyioXPFWryA8PKAMUPQRBin94qLqsax0X30BN8kQMhJVHEsJUXV7N9j/4QddQtbYca3mLCYeK4isoAPP3NKKglUnpMJUBZf3CaDrSiac/Xcih6KeS80zM RMecDJ/3TL25qns/CRRTEDWOE2PVzoPXtNssIdzPRPqg2uLyEEEW2ITbogXKP6vCu2dGANFHT77lKqrxc B23Wa2wRCHpbuZr0f5N0kLg9EgTi.vnxEkRm3q267rc20/7ouaZSidjt+auVgqjnboqjVHU= eltex-pg2-v26@eltext
    root@eltex-practice2-pg2-v26:~#

***Содержимое файла ключа на сервере 1.***  

    eltex-pg2-v26@eltext:~$ cat .ssh/id_rsa.pub  
    ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCjKfL26WWGWFAqW7ih+TtVK0sHPpJn7J01Q1PJE0zJIG7lvcTEwRojH5ehcZ6C5LlNtzDeOcgQDKvIlfoX/H/KllIC5AFgPWsSAfIG59MMjYQV0X6dwuqhgwM6otRox/gLjIBC9GCYuG5YKGdLrQjxRGKKD6A5UTADHgY4f768u50zxWQQ2RMBUoqBcUSX0wmkxwZ7NNUbJWE8RB8SXLYXjSs7WrC9L1dYNRhG2ANiCFIJr7NFpxyioXPFWryA8PKAMUPQRBin94qLqsax0X30BN8kQMhJVHEsJUXV7N9j/4QddQtbYca3mLCYeK4isoAPP3NKKglUnpMJUBZf3CaDrSiac/Xcih6KeS80zM RMecDJ/3TL25qns/CRRTEDWOE2PVzoPXtNssIdzPRPqg2uLyEEEW2ITbogXKP6vCu2dGANFHT77lKqrxc B23Wa2wRCHpbuZr0f5N0kLg9EgTi.vnxEkRm3q267rc20/7ouaZSidjt+auVgqjnboqjVHU= eltex-pg2-v26@eltext
    eltex-pg2-v26@eltext:~$  

### 4.Создайте пользователя user1 при помощи команды useradd, укажите необходимость создания домашнего каталога и shell /bin/bash. Создайте пароль пользователю user1  
`-s - командная оболочка для пользователя.`  
`-m - создавать домашний каталог пользователя, если он не существует.`  

    root@eltex-practice2-pg2-v26:~# sudo useradd -m -s /bin/bash user1
    root@eltex-practice2-pg2-v26:~# sudo passwd user1
    New password:
    Retype new password:
    passwd: password updated successfully
    root@eltex-practice2-pg2-v26:~#

### 5.Создайте пользователя user2 и user3 при помощи команды adduser  
`-s - командная оболочка для пользователя.`  
`-m - создавать домашний каталог пользователя, если он не существует.`  

    root@eltex-practice2-pg2-v26:~# sudo useradd -m -s /bin/bash user2
    root@eltex-practice2-pg2-v26:~# sudo useradd -m -s /bin/bash user3
    root@eltex-practice2-pg2-v26:~# sudo passwd user2
    New password:
    Retype new password:
    passwd: password updated successfully
    root@eltex-practice2-pg2-v26:~# sudo passwd user3
    New password:
    Retype new password:
    passwd: password updated successfully
    root@eltex-practice2-pg2-v26:~#

### 6.Для пользователя user3 смените shell на /usr/sbin/nologin (man usermod), выполните вход под этим пользователем при помощи утилиты su,сначала без дополнительных параметров, затем с явным указанием shell /bin/bash в параметрах su. Выполните logout  

    root@eltex-practice2-pg2-v26:~# sudo usermod -s /usr/sbin/nologin user3
    root@eltex-practice2-pg2-v26:~# su user3
    This account is currently not available.
    root@eltex-practice2-pg2-v26:~# su -s /bin/bash user3
    user3@eltex-practice2-pg2-v26:/root$ logout
    bash: logout: not login shell: use 'exit'
    [sudo] password for user3:
    user3 is not in the sudoers file.
    user3@eltex-practice2-pg2-v26:/root$ exit
    root@eltex-practice2-pg2-v26:~#

***/usr/sbin/nologin запрещает пользователю вход в систему.***  
***При попытке войти под пользователем user3 с помощью команды su, выдается сообщение: This account is currently not available.***    
***При попытке явно указать shell /bin/bash вход успешно выполнился.***  
***Команда logout не выполнилась, потому что текущий shell был запущен через su.***  

### 7.Создайте новую группу и добавьте её для всех пользователей user* как дополнительную, посмотрите список групп всех пользователей user*  
    root@eltex-practice2-pg2-v26:~# sudo groupadd new_group
    root@eltex-practice2-pg2-v26:~# sudo usermod -aG new_group user1
    root@eltex-practice2-pg2-v26:~# sudo usermod -aG new_group user2
    root@eltex-practice2-pg2-v26:~# sudo usermod -aG new_group user3
    root@eltex-practice2-pg2-v26:~#

***Проверка принадлежности пользователей к группам.***  

    root@eltex-practice2-pg2-v26:~# groups user1
    user1 : user1 new_group
    root@eltex-practice2-pg2-v26:~# groups user2
    user2 : user2 new_group
    root@eltex-practice2-pg2-v26:~# groups user3
    user3 : user3 new_group
    root@eltex-practice2-pg2-v26:~#
### 9.Создайте каталог /opt/share и назначьте группу из предыдущего пункта его владельцем, установите на этот каталог бит SGID, права для группы rwx.  
***Создаем каталог и устанавливаем бит SGID***   

    root@eltex-practice2-pg2-v26:~# mkdir /opt/share
    root@eltex-practice2-pg2-v26:~# sudo chown :new_group /opt/share
    root@eltex-practice2-pg2-v26:~# sudo chown 2770 /opt/share/
    root@eltex-practice2-pg2-v26:~#

***Проверяем права***  

    root@eltex-practice2-pg2-v26:~# ls -ld /opt/share/
    drwxrws--- 2 root new_group 4096 Mar 15 15:06 /opt/share/
    root@eltex-practice2-pg2-v26:~#

***бит SGID установлен. Новые файлы и подддиректории будут наследовать группу new_group.***   

### 10.Для user1 задайте перманентно umask, снимающий право чтения для «прочих»  
Чтобы получить маску снимающий право чтения для «прочих» должно быть значение (rw-r-----) 640. Т.е убрать запись для группы (-w-) 2 и все права на прочих (rwx)7  
Маска будет равна 027  
***Добавляем значение umask 0027 в /home/user1/.bashrc.***
***Сохраняем изменения source /home/user1/.bashrc***  

    root@eltex-practice2-pg2-v26:~# tail /home/user1/.bashrc
    # this, if it's already enabled in /etc/bash.bashrc and /etc/profile
    # sources /etc/bash.bashrc).
    if ! shopt -q posix; then
        if [ -f /usr/share/bash-completion/bash_completion ]; then
            . /usr/share/bash-completion/bash_completion
        elif [ -f /etc/bash_completion ]; then
            . /etc/bash_completion
        fi
    fi

    umask 0027
    root@eltex-practice2-pg2-v26:~#

***Переключаемся на user1 и проверяем значение umask***  

    root@eltex-practice2-pg2-v26:~# su - user1
    user1@eltex-practice2-pg2-v26:~$ umask
    0027
    user1@eltex-practice2-pg2-v26:~$

### 11.Создайте каждым из пользователей новые файлы в каталоге /opt/share, удалите файлы созданные другими пользователями  
***Создаем фалы каждым пользователем***  

    root@eltex-practice2-pg2-v26:~# su - user1
    user1@eltex-practice2-pg2-v26:~$ touch /opt/share/file1.txt
    user1@eltex-practice2-pg2-v26:~$ su - user2
    Password:
    user2@eltex-practice2-pg2-v26:~$ touch /opt/share/file2.txt
    user2@eltex-practice2-pg2-v26:~$ su - user3
    This account is currently not available.
    root@eltex-practice2-pg2-v26:~# su -s /bin/bash user3
    user3@eltex-practice2-pg2-v26:/root$ touch /opt/share/file3.txt

***Проверяем права***  

    user3@eltex-practice2-pg2-v26:/root$ ls -l /opt/share/
    total 0
    -rw-r----- 1 user1 new_group 0 Mar 16 10:22 file1.txt
    -rw-r----- 1 user2 new_group 0 Mar 16 10:22 file2.txt
    -rw-r----- 1 user3 new_group 0 Mar 16 10:31 file3.txt
    user3@eltex-practice2-pg2-v26:/root$

***Каждый файл создан разными пользователями, принадлежащими группе new_group***   

***Удаляем файлы созданные другими пользователями***   

    user3@eltex-practice2-pg2-v26:/root$ rm /opt/share/file1.txt
    rm: remove write-protected regular empty file '/opt/share/file1.txt'? y
    user3@eltex-practice2-pg2-v26:/root$ su - user1
    Password:
    user1@eltex-practice2-pg2-v26:~$ rm /opt/share/file2.txt
    Password:
    user2@eltex-practice2-pg2-v26:~$ rm /opt/share/file3.txt
    user2@eltex-practice2-pg2-v26:~$ ls -l
    total 0

***Все файлы удалены***  

### 12.Повторите предыдущий пункт, предварительно установив sticky bit на каталоге /opt/share  
***Установка sticky bit***   

    root@eltex-practice2-pg2-v26:~# sudo chmod +t /opt/share/
    root@eltex-practice2-pg2-v26:~# ls -ld /opt/share/
    drwxrws-T 2 root new_group 4096 Mar 16 10:42 /opt/share/
    root@eltex-practice2-pg2-v26:~#

***Попытка удалить файлы других пользователей***  

    user3@eltex-practice2-pg2-v26:/root$ rm /opt/share/file1.txt
    rm: remove write-protected regular empty file '/opt/share/file1.txt'? y
    rm: cannot remove '/opt/share/file1.txt': Operation not permitted
    user1@eltex-practice2-pg2-v26:~$ rm /opt/share/file2.txt
    rm: cannot remove '/opt/share/file2.txt': Operation not permitted
    user2@eltex-practice2-pg2-v26:~$ rm /opt/share/file3.txt
    rm: cannot remove '/opt/share/file3.txt': Operation not permitted
    user2@eltex-practice2-pg2-v26:~$ rm /opt/share/file1.txt
    rm: remove write-protected regular empty file '/opt/share/file1.txt'? y
    rm: cannot remove '/opt/share/file1.txt': Operation not permitted

***директория содержит sticky bit ,пользователи не имеют права удалять файлы, созданные другими пользователями***  

### 13.Разрешите user1 выполнять привилегированную команду dmesg при помощи команды sudo, а user2 – при помощи скрипта на языке bash с установленным флагом SUID  

***Открываем sudo visudo и добавояем строку user1 ALL=(ALL) NOPASSWD: /bin/dmesg.***  
***Строка user1 ALL=(ALL) NOPASSWD: /bin/dmesg разрешает запускать dmesg без ввода пароля***  

    root@eltex-practice2-pg2-v26:~# which dmseg
    /usr/bin/dmesg
    root@eltex-practice2-pg2-v26:~# tail visudo
    user1 ALL=(ALL) NOPASSWD: /usr/bin/dmesg
    root@eltex-practice2-pg2-v26:~#

***Заходим под user1 и пытаемся выпольнить команду sudo dmesg***  

    root@eltex-practice2-pg2-v26:~# su - user1
    user1@eltex-practice2-pg2-v26:~# sudo dmesg
    [sudo] password for user1:
    user1 is not in the sudoers file.
    user1@eltex-practice2-pg2-v26:~$ exit
    logout
    root@eltex-practice2-pg2-v26:~# sudo usermod -aG sudo user1
    root@eltex-practice2-pg2-v26:~# su - user1
    To run a command as administrator (user "root"), use "sudo <command>". See "man sudo_root" for details.

***При попытке выполнить команду sudo dmesg выдается ошибка что пользователи не может выполнять команду sudo т.к он не включен в sudoers***  
***Добавляем пользователя в группу sudo***  
***Повторно запускаем команду sudo dmesg***  

    user1@eltex-practice2-pg2-v26:~$ sudo dmesg
    [sudo] password for user1: 
    [    0.000000] Linux version 6.8.0-55-generic (buildd@lcy02-amd64-095) (x86_64-linux-gnu-gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0, GNU ld (GNU Binutils for Ubuntu) 2.42) #57-Ubuntu SMP PREEMPT_DYNAMIC Wed Feb 12 23:42:21 UTC 2025 (Ubuntu 6.8.0-55.57-generic 6.8.12)
    [    0.000000] Command line: BOOT_IMAGE=/vmlinuz-6.8.0-55-generic root=/dev/mapper/ubuntu--vg-ubuntu--lv ro
    [    0.000000] KERNEL supported cpus:
    [    0.000000]   Intel GenuineIntel
    [    0.000000]   AMD AuthenticAMD
    [    0.000000]   Hygon HygonGenuine
    [    0.000000]   Centaur CentaurHauls
    [    0.000000]   zhaoxin   Shanghai  
    [    0.000000] BIOS-provided physical RAM map:
    [    0.000000] BIOS-e820: [mem 0x0000000000000000-0x000000000009fbff] usable
    [    0.000000] BIOS-e820: [mem 0x000000000009fc00-0x000000000009ffff] reserved
    [    0.000000] BIOS-e820: [mem 0x00000000000f0000-0x00000000000fffff] reserved
    [    0.000000] BIOS-e820: [mem 0x0000000000100000-0x00000000bffd9fff] usable
    [    0.000000] BIOS-e820: [mem 0x00000000bffda000-0x00000000bfffffff] reserved
    [    0.000000] BIOS-e820: [mem 0x00000000feffc000-0x00000000feffffff] reserved
    [    0.000000] BIOS-e820: [mem 0x00000000fffc0000-0x00000000ffffffff] reserved
    [    0.000000] BIOS-e820: [mem 0x0000000100000000-0x000000013fffffff] usable
    [    0.000000] BIOS-e820: [mem 0x000000fd00000000-0x000000ffffffffff] reserved
    [    0.000000] NX (Execute Disable) protection: active
    [    0.000000] APIC: Static calls initialized
    [    0.000000] SMBIOS 2.8 present.
    [    0.000000] DMI: QEMU Standard PC (i440FX + PIIX, 1996), BIOS rel-1.16.3-0-ga6ed6b701f0a-prebuilt.qemu.org 04/01/2014
    [    0.000000] Hypervisor detected: KVM
    ....
 
 ***Создаем скрипт который запускает команду dmesg для user2***  

    root@eltex-practice2-pg2-v26:~# touch /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~# nano /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~# tail /usr/local/bin/script_dmesg.sh
    #!/bin/bash
    /bin/dmesg
    root@eltex-practice2-pg2-v26:~#

***Даем root-владение и устанавливаем флаг SUID***  

    root@eltex-practice2-pg2-v26:~# sudo chown root:root /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~# sudo chmod u+s /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~# ls -l /usr/local/bin/script_dmesg.sh
    -rwSr----- 1 root root 23 Mar 16 11:14 /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~#

***Бит SUID установлен, но файл не является исполняемым. Исправляем это***   

    root@eltex-practice2-pg2-v26:~# sudo chmod +x /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~# ls -l /usr/local/bin/script_dmesg.sh
    -rwsr-x--x 1 root root 23 Mar 16 11:14 /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~#

***Заходим под user2 и пытаем выполнить скрипт***  

    root@eltex-practice2-pg2-v26:~# su - user2
    user2@eltex-practice2-pg2-v26:~$ bash /usr/local/bin/script_dmesg.sh
    bash: /usr/local/bin/script_dmesg.sh: Permission denied
    user2@eltex-practice2-pg2-v26:~$ tail /usr/local/bin/script_dmesg.sh
    tail: cannot open '/usr/local/bin/script_dmesg.sh' for reading: Permission denied
    user2@eltex-practice2-pg2-v26:~$ ls -l /usr/local/bin/script_dmesg.sh
    -rwsr-x--x 1 root root 23 Mar 16 11:14 /usr/local/bin/script_dmesg.sh
    user2@eltex-practice2-pg2-v26:~$

***Добавим права на чтения***  

    root@eltex-practice2-pg2-v26:~# sudo chmod 4755 /usr/local/bin/script_dmesg.sh
    root@eltex-practice2-pg2-v26:~# su - user2
    user2@eltex-practice2-pg2-v26:~$ bash /usr/local/bin/script_dmesg.sh
    dmesg: read kernel buffer failed: Operation not permitted
    user2@eltex-practice2-pg2-v26:~$ /usr/local/bin/script_dmesg.sh
    dmesg: read kernel buffer failed: Operation not permitted
    user2@eltex-practice2-pg2-v26:~$ ls -l /usr/local/bin/script_dmesg.sh
    -rwsr-xr-x 1 root root 23 Mar 16 11:14 /usr/local/bin/script_dmesg.sh
    user2@eltex-practice2-pg2-v26:~$

***user2 теперь может выпольнить скрипт, но теперь получаем ошибку к доступа к ядру буфера***  

### 14.Для всех пользователей user* задайте время действия пароля – 10 дней.  

***Команда chage -l user показывает текущие настройки управления паролем для пользователя user***  

    root@eltex-practice2-pg2-v26:~# chage -l user1
    Last password change : Mar 13, 2025
    Password expires     : never
    Password inactive    : never
    Account expires      : never
    Minimum number of days between password change       : 0
    Maximum number of days between password change       : 99999
    Number of days of warning before password expires    : 7

***Изменим срока действия пароля для user1***   

    root@eltex-practice2-pg2-v26:~# chage -M 10 user1
    root@eltex-practice2-pg2-v26:~# chage -l user1
    Last password change : Mar 13, 2025
    Password expires     : Mar 23, 2025
    Password inactive    : never
    Account expires      : never
    Minimum number of days between password change       : 0
    Maximum number of days between password change       : 10
    Number of days of warning before password expires    : 7

    root@eltex-practice2-pg2-v26:~#

***Изменим срока действия пароля для user2***  

    root@eltex-practice2-pg2-v26:~# chage -l user2
    Last password change : Mar 13, 2025
    Password expires     : never
    Password inactive    : never
    Account expires      : never
    Minimum number of days between password change       : 0
    Maximum number of days between password change       : 99999
    Number of days of warning before password expires    : 7

    root@eltex-practice2-pg2-v26:~# chage -M 10 user2
    root@eltex-practice2-pg2-v26:~# chage -l user2
    Last password change : Mar 13, 2025
    Password expires     : Mar 23, 2025
    Password inactive    : never
    Account expires      : never
    Minimum number of days between password change       : 0
    Maximum number of days between password change       : 10
    Number of days of warning before password expires    : 7

    root@eltex-practice2-pg2-v26:~#

***Изменим срока действия пароля для user3***  

    root@eltex-practice2-pg2-v26:~# chage -l user3
    Last password change : Mar 13, 2025
    Password expires     : never
    Password inactive    : never
    Account expires      : never
    Minimum number of days between password change       : 0
    Maximum number of days between password change       : 99999
    Number of days of warning before password expires    : 7

    root@eltex-practice2-pg2-v26:~# chage -M 10 user3
    root@eltex-practice2-pg2-v26:~# chage -l user3
    Last password change : Mar 13, 2025
    Password expires     : Mar 23, 2025
    Password inactive    : never
    Account expires      : never
    Minimum number of days between password change       : 0
    Maximum number of days between password change       : 10
    Number of days of warning before password expires    : 7

    root@eltex-practice2-pg2-v26:~#


### 15.Отредактируйте файл /etc/motd, вписав туда свое имя и фамилию  

    root@eltex-practice2-pg2-v26:~# nano /etc/motd
    root@eltex-practice2-pg2-v26:~# cat /etc/motd
    Turtugeshev Aleksey
    root@eltex-practice2-pg2-v26:~#

### 16.Создайте копию содержимого каталога /etc в каталог /root/etc_backup при помощи программы rcync  

`-v - Выводить подробную информацию о процессе копирования.`    
`-a - Режим архивирования, когда сохраняются все атрибуты оригинальных файлов.`  
`--progress - Выводить прогресс передачи файла.`  

    root@eltex-practice2-pg2-v26:~# mkdir /root/etc_backup
    root@eltex-practice2-pg2-v26:~# sudo rsync -av --process /etc/ /root/etc_backup/
    rsync error: syntax or usage error (code 1) at main.c(1795) [client=3.2.7]
    root@eltex-practice2-pg2-v26:~# sudo rsync -av --progress /etc/ /root/etc_backup/
    sending incremental file list
    ./
    .pwd.lock
            0   100%    0.00kB/s    0:00:00 (xfr#1, ir-chk=1204/1206)
    .resolv.conf.systemd-resolved.bak
        862   100%    0.00kB/s    0:00:00 (xfr#2, ir-chk=1203/1206)
    .updated
        208   100%    9.23kB/s    0:00:00 (xfr#3, ir-chk=1202/1206)
    adduser.conf
        3,444   100%   146.23kB/s    0:00:00 (xfr#4, ir-chk=1201/1206)
    bash.bashrc
    2,319   100%   98.46kB/s    0:00:00 (xfr#5, ir-chk=1200/1206)
    bash_completion
        45   100%    1.91kB/s    0:00:00 (xfr#6, ir-chk=1199/1206)
    bindresvport.blacklist
        367   100%   19.93kB/s    0:00:00 (xfr#7, ir-chk=1198/1206)
    ...


***Содержимое каталога etc_backup***  

    root@eltex-practice2-pg2-v26:~ # ls /root/etc_backup
    ModemManager            iscsi                python3.12
    PackageKit              issue                qemu
    UPower                  issue.net            rc0.d
    X11                     kernel               rc1.d
    adduser.conf            landscape            rc2.d
    alternatives            ld.so.cache          rc3.d
    apparmor                ld.so.conf           rc4.d
    apparmor.d              ld.so.conf.d         rc5.d
    apport                  ldap                 rc6.d
    apt                     legal                rcS.d
    bash.bashrc             libaudit.conf        resolv.conf
    bash_completion         libblockdev          rmt
    bash_completion.d       libibverbs.d         rpc
    bindresvport.blacklist  libnl-3              rsyslog.conf
    binfmt.d                locale.alias         rsyslog.d
    byobu                   locale.conf          screenrc
    ca-certificates         locale.gen           security
    ca-certificates.conf    localtime            selinux
    cloud                   logcheck             sensors.d
    console-setup           login.defs           sensors3.conf
    credstore               logrotate.conf       services
    credstore.encrypted     logrotate.d          sgml
    cron.d                  lsb-release          shadow
    cron.daily              lvm                  shadow-
    cron.hourly             machine-id           shells
    cron.monthly            magic                skel
    cron.weekly             magic.mime           sos
    cron.yearly             manpath.config       ssh
    crontab                 mdadm                ssl
    cryptsetup-initramfs    mime.types           subgid
    crypttab                mke2fs.conf          subgid-
    dbus-1                  modprobe.d           subuid
    debconf.conf            modules              subuid-
    debian_version          modules-load.d       sudo.conf
    default                 motd                 sudo_logsrvd.conf
    deluser.conf            mtab                 sudoers
    depmod.d                multipath            sudoers.d
    dhcp                    multipath.conf       supercat
    dhcpcd.conf             nanorc               sysctl.conf
    dpkg                    needrestart          sysctl.d
    e2scrub.conf            netconfig            sysstat
    environment             netplan              systemd
    ethertypes              network              terminfo
    fonts                   networkd-dispatcher  thermald
    fstab                   networks             timezone
    fuse.conf               newt                 tmpfiles.d
    fwupd                   nftables.conf        ubuntu-advantage
    gai.conf                nsswitch.conf        ucf.conf
    gnutls                  opt                  udev
    groff                   os-release           udisks2
    group                   overlayroot.conf     ufw
    group-                  pam.conf             update-manager
    grub.d                  pam.d                update-motd.d
    gshadow                 passwd               update-notifier
    gshadow-                passwd-              usb_modeswitch.conf
    gss                     perl                 usb_modeswitch.d
    hdparm.conf             pki                  vconsole.conf
    host.conf               plymouth             vim
    hosts                   pm                   vmware-tools
    hosts.allow             polkit-1             vtrgb
    hosts.deny              pollinate            wgetrc
    init.d                  profile              xattr.conf
    initramfs-tools         profile.d            xdg
    inputrc                 protocols            xml
    iproute2                python3              zsh_command_not_found
    root@eltex-practice2-pg2-v26:~ # 


### 17.Заархивируйте содержимое каталога /root/etc_backup архиватором tar, используйте алгоритмы сжатия gzip, bzip2, 7zip, сравните размеры полученных файлов  
***Флаги:***    
`c - создать архив`        
`f - файл для записи архива`  
`C - распаковать в указанную папку`  

***gzip***  
`z - сжать архив с помощью Gzip`  

    root@eltex-practice2-pg2-v26:~# sudo tar -czf /root/etc_backup_gzip.tar.gz -C /root etc_backup
    root@eltex-practice2-pg2-v26:~# ls /root/
    etc_backup  etc_backup_gzip.tar.gz visudo
    root@eltex-practice2-pg2-v26:~# 

***Bzip2***  
`j - сжать архив с помощью Bzip`  

    root@eltex-practice2-pg2-v26:~# sudo tar -cjf /root/etc_backup_bzip2.tar.bz2 -C /root etc_backup
    root@eltex-practice2-pg2-v26:~# ls /root/
    etc_backup  etc_backup_gzip.tar.gz  etc_backup_bzip2.tar.bz2
    root@eltex-practice2-pg2-v26:~#

***7zip***  
`a - создается новый архив etc_backup_7z.7z`  

    root@eltex-practice2-pg2-v26:~# 7z a /root/etc_backup_7z.7z /root/etc_backup
    7-Zip 23.01 (x64) : Copyright (c) 1999-2023 Igor Pavlov : 2023-06-20
    64-bit locale=C.UTF-8 Threads:2 OPEN_MAX=1024
    Scanning the drive:
    WARNING: errno=2 : No such file or directory
    /root/etc_backup/os-release
    WARNING: errno=2 : No such file or directory
    /root/etc_backup/resolv.conf
    WARNING: errno=2 : No such file or directory
    /root/etc_backup/mtab
    244 folders, 1506 files, 38698012 bytes (37 MiB)
    Creating archive: /root/etc_backup_7z.7z
    Add new data to archive: 244 folders, 1506 files, 38698012 bytes (37 MiB)
    Files read from disk: 1493
    Archive size: 4676412 bytes (4567 KiB)
    Scan WARNINGS for files and folders:
    /root/etc_backup/os-release : errno=2 : No such file or directory
    /root/etc_backup/resolv.conf : errno=2 : No such file or directory
    /root/etc_backup/mtab : errno=2 : No such file or directory
    ----------------
    Scan WARNINGS: 3
    root@eltex-practice2-pg2-v26:~#

`В процессе было выдано 3 предупреждения о том, что некоторые файлы не были найдены`   

***Сравнение размеров полученных файлов***  

    root@eltex-practice2-pg2-v26:~# ls -lh
    total 5.6M
    drwxr-xr-x 1 root root 4.0K Mar 16 11:44 etc_backup
    -rw-r----- 1 root root 4.5M Mar 16 12:12 etc_backup_7z.7z
    -rw-r----- 1 root root 547K Mar 16 12:02 etc_backup_bzip2.tar.bz2
    -rw-r----- 1 root root 581K Mar 16 11:58 etc_backup_gzip.tar.gz
    root@eltex-practice2-pg2-v26:~#

`Наименьший из всех bzip2`

### 18.Отредактируйте файл /etc/motd, вписав туда текущую дату и время, синхронизируйте каталог /root/etc_backup с каталогом /etc при помощи rsync, добавьте файл motd в архив, сжатый gzip  

***Добавим текущую дату***  

    root@eltex-practice2-pg2-v26:~# cat /etc/motd
    Turtugeshev Aleksey
    Sun Mar 16 12:55:50 UTC 2025

    root@eltex-practice2-pg2-v26:~#


***Синхронизируем каталог /root/etc_backup с каталогом /etc***  

    root@eltex-practice2-pg2-v26:~# rsync -av --delete /etc/ /root/etc_backup/
    sending incremental file list

    sent 69,649 bytes  received 260 bytes  139,818.00 bytes/sec
    total size is 2,302,119  speedup is 33.79

    root@eltex-practice2-pg2-v26:~# ls -lh
    total 5.6M
    drwxr-xr-x 1 root root 4.0K Mar 16 11:44 etc_backup
    -rw-r----- 1 root root 4.5M Mar 16 12:12 etc_backup_7z.7z
    -rw-r----- 1 root root 547K Mar 16 12:02 etc_backup_bzip2.tar.bz2
    -rw-r----- 1 root root 581K Mar 16 11:58 etc_backup_gzip.tar.gz

    root@eltex-practice2-pg2-v26:~# sudo tar -czf /root/etc_backup_gzip.tar.gz -C /root etc/motd
    tar: Removing leading '/' from member names
    tar: Removing leading '/' from hard link targets



### 19.Сравните содержимое архива, упакованного bzip2 с сорержимым каталога /root/etc_backup  

***Создадим новый каталог tmp_backup_bzip2,распакуем туда архив bzip и сравнив с помощью diff***  

    root@eltex-practice2-pg2-v26:~# mkdir tmp_backup_bzip2
    root@eltex-practice2-pg2-v26:~# tar -xjf /root/etc_backup_bzip2.tar.bz2 -C tmp_backup_bzip2/
    root@eltex-practice2-pg2-v26:~# diff -r tmp_backup_bzip2/ /root/etc_backup/
    Only in /root/etc_backup: .pwd.lock
    Only in /root/etc_backup: resolv.conf.systemd-resolved.bak
    Only in /root/etc_backup: updated
    Only in /root/etc_backup: PackageKit
    Only in /root/etc_backup: UPower
    Only in /root/etc_backup: X11
    Only in /root/etc_backup: adduser.conf
    Only in /root/etc_backup: alternatives
    Only in /root/etc_backup: apparmor.d
    Only in /root/etc_backup: apt
    Only in /root/etc_backup: bash_completion
    Only in /root/etc_backup: bash_completion.d
    Only in /root/etc_backup: bindresvport.blacklist
    Only in /root/etc_backup: binfmt.d
    Only in /root/etc_backup: byobu
    Only in /root/etc_backup: ca-certificates
    Only in /root/etc_backup: ca-certificates.conf
    Only in /root/etc_backup: cloud

### 20.Распакуйте архивы etc_backup, упакованные gzip и 7zip в каталоги /root/etc_backup_gzip и /root/etc_backup_7zip, сравните программой diff файлы motd в этих каталогах.


***

    root@eltex-practice2-pg2-v26:~# mkdir /root/etc_backup_gzip
    root@eltex-practice2-pg2-v26:~# mkdir /root/etc_backup_7zip
    root@eltex-practice2-pg2-v26:~# tar -xzf /root/etc_backup_gzip.tar.gz -C etc_backup_gzip/
    root@eltex-practice2-pg2-v26:~# 7z x /root/etc_backup_7z.7z -o/root/etc_backup_7zip

    7-Zip 23.01 (x64) : Copyright (c) 1999-2023 Igor Pavlov : 2023-06-20
    64-bit locale=C.UTF-8 Threads:2 OPEN_MAX=1024

    Scanning the drive for archives:
    1 file, 4676412 bytes (4567 KiB)

    Extracting archive: /root/etc_backup_7z.7z
    --
    Path = /root/etc_backup_7z.7z
    Type = 7z
    Physical Size = 4676412
    Headers Size = 20618
    Method = LZMA2:24 BCJ
    Solid = +
    Blocks = 2

    Everything is Ok

    Folders: 244
    Files: 1506
    Size: 38698012
    Compressed Size: 4676412

    root@eltex-practice2-pg2-v26:~# diff etc_backup_gzip/etc_backup/motd etc_backup_7zip/etc_backup/motd
    2d1
    < Sun Mar 16 12:55:50 UTC 2025
    root@eltex-practice2-pg2-v26:~#
`Архив 7zip содержит старую версию файла /etc/motd, а архив gzip — новую из п 18.`
