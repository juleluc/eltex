## Задания. Раздел 3

### 1.Перейдите в домашний каталог, создайте файл $USER_part3.log. Используемые в разделе 3 команды дописывайте в файл командой echo, не забудьте про экранирование.  
    eltex-pg2-v26@eltex~$ cd ~
    eltex-pg2-v26@eltex~$ touch ${USER}_part3.log
    eltex-pg2-v26@eltex~$ ls
    2025-01  2025-04  2025-07  2025-10  eltex-pg2-v26_part3.log  task_1_1.md
    2025-02  2025-05  2025-08  2025-11  eltex-pg2-v26_part.log
    2025-03  2025-06  2025-09  2025-12  report_part1.txt
    eltex-pg2-v26@eltex~$ 

***Добавление команды в лог-файл:***  

    eltex-pg2-v26@eltex~$ echo "cd ~" >> ${USER}_part3.log
    eltex-pg2-v26@eltex~$ echo "touch \${USER}_part3.log" >> ${USER}_part3.log
    eltex-pg2-v26@eltex~$ cat eltex-pg2-v26_part3.log 
    cd ~
    touch ${USER}_part3.log

### 2. Создайте иерархию вложенных каталогов D1/D2/D3.  
    eltex-pg2-v26@eltex~$ mkdir -p D1/D2/D3
    eltex-pg2-v26@eltex~$ ls
    2025-01  2025-04  2025-07  2025-10  D1                       report_part1.txt
    2025-02  2025-05  2025-08  2025-11  eltex-pg2-v26_part3.log  task_1_1.md
    2025-03  2025-06  2025-09  2025-12  eltex-pg2-v26_part.log
    eltex-pg2-v26@eltex~$ 


### 3. В каталоге D2 создайте обычный пустой файл file.txt.
    eltex-pg2-v26@eltex~$ touch D1/D2/file.txt
    eltex-pg2-v26@eltex~$ ls D1/D2/
    D3  file.txt
    eltex-pg2-v26@eltex~$ 

### 4. Добавьте произвольный текст в файл file.txt.  
    eltex-pg2-v26@eltex~$ echo "f1f2f3" > D1/D2/file.txt
    eltex-pg2-v26@eltex~$ echo "echo \"f1f2f3\" > D1/D2/file.txt" >> ${USER}_part3.log
    eltex-pg2-v26@eltex~$ cat D1/D2/file.txt 
    f1f2f3
    eltex-pg2-v26@eltex~$ 

### 5. В каталоге D3 создайте символическую и жесткие ссылки на file.txt.
    eltex-pg2-v26@eltex~$ ln D1/D2/file.txt D1/D2/D3/hardlink.txt
    eltex-pg2-v26@eltex~$ ln -s D1/D2/file.txt D1/D2/D3/softlink.txt
    eltex-pg2-v26@eltex~$ 

### 6. Докажите, что ссылки созданы успешно.
    eltex-pg2-v26@eltex~$ ls -ali D1/D2/D3/
    total 12
    917739 drwxr-xr-x 2 eltex-pg2-v26 eltex-pg2-v26 4096 мар 20 21:49 .
    917738 drwxr-xr-x 3 eltex-pg2-v26 eltex-pg2-v26 4096 мар 20 21:06 ..
    917740 -rw-r--r-- 2 eltex-pg2-v26 eltex-pg2-v26    7 мар 20 21:08 hardlink.txt
    917741 lrwxrwxrwx 1 eltex-pg2-v26 eltex-pg2-v26   14 мар 20 21:49 softlink.txt -> D1/D2/file.txt
    eltex-pg2-v26@eltex~$ 


### 7. Переместите файл file.txt в каталог D1.  
    eltex-pg2-v26@eltex~$ mv D1/D2/file.txt D1/
    eltex-pg2-v26@eltex~$ ls D1/
    D2  file.txt
    eltex-pg2-v26@eltex~$ 


### 8. Проверьте работу ранее созданных ссылок на файл file.txt. Какая ссылка оказалась рабочей и почему?
    eltex-pg2-v26@eltex~$ ls -ali D1/D2/D3
    total 12
    917739 drwxr-xr-x 2 eltex-pg2-v26 eltex-pg2-v26 4096 мар 20 21:49 .
    917738 drwxr-xr-x 3 eltex-pg2-v26 eltex-pg2-v26 4096 мар 20 21:54 ..
    917740 -rw-r--r-- 2 eltex-pg2-v26 eltex-pg2-v26    7 мар 20 21:08 hardlink.txt
    917741 lrwxrwxrwx 1 eltex-pg2-v26 eltex-pg2-v26   14 мар 20 21:49 softlink.txt -> D1/D2/file.txt
    eltex-pg2-v26@eltex~$ cat D1/D2/D3/hardlink.txt 
    f1f2f3
    eltex-pg2-v26@eltex~$ cat D1/D2/D3/softlink.txt 
    cat: D1/D2/D3/softlink.txt: No such file or directory
    eltex-pg2-v26@eltex~$ 

***Жесткая ссылка работает, т.к. она ссылается на inode, который не изменился.***  
***А символическая ссылка не работает, потому что указанный в ней путь является относительным и ОС не может найти файл по этому пути.*** 
### 9. Удалите каталог D2 со всем содержимым.  
    eltex-pg2-v26@eltex~$ rm -r D1/D2
    eltex-pg2-v26@eltex~$ ls D1/
    file.txt
    eltex-pg2-v26@eltex~$ 

### 10. Найдите все файлы в системе размером больше 50МБ. Убедитесь в том, что найденные файлы имеют нужный размер. Запишите в файл $USER_part3_gt50M.log список найденных файлов.
1. Найти файлы размером больше 50Мб.
 - 2>/dev/null перенаправляет все ошибки 

        eltex-pg2-v26@eltex~$ find / -type f -size +50M 2>/dev/null
        /proc/kcore
2. Записать в файл $USER_part3_gt50M.log  

        eltex-pg2-v26@eltex~$ find / -type f -size +50M 2>/dev/null > ${USER}_part3_gt50M.log
        eltex-pg2-v26@eltex~$ cat eltex-pg2-v26_part3_gt50M.log 
        /proc/kcore
        eltex-pg2-v26@eltex~$ 

### 11. В домашнем каталоге и его подкаталогах найдите обычные файлы, которые были изменены в течение последних 24х часов.  

***Флаг -mtime фильтрует файлы по времени их последнего изменения.***  
***-1 означает изменения в течение последних 24 часов.***  
***-type f - обычные файлы.***  
***~ - поиск с корневого каталога.***  

    eltex-pg2-v26@eltex~$ find ~ -type f -mtime -1
    /home/eltex-pg2-v26/.viminfo
    /home/eltex-pg2-v26/eltex-pg2-v26_part.log
    /home/eltex-pg2-v26/report_part1.txt
    /home/eltex-pg2-v26/.log
    /home/eltex-pg2-v26/eltex-pg2-v26_part3.log
    /home/eltex-pg2-v26/eltex-pg2-v26_part3_gt50M.log
    /home/eltex-pg2-v26/task_1_1.md
    /home/eltex-pg2-v26/D1/file.txt
    /home/eltex-pg2-v26/.bash_history
    /home/eltex-pg2-v26/.bashrc
    eltex-pg2-v26@eltex~$ 


### 13. В каком каталоге находится команда find?  
***Воспользуемся утилитой which.***  

        eltex-pg2-v26@eltex~$ which find
        /usr/bin/find
        eltex-pg2-v26@eltex~$ 


### 14. Определите характер содержимого файла find командой file.
***Команда file используется в Linux для определения типа файла. Она анализирует содержимое файла и выводит информацию о его типе***  

        eltex-pg2-v26@eltex~$ file $(which find)
        /usr/bin/find: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=5545a6c7162d325fbe5ffabcbfe4e5521b66ce70, for GNU/Linux 3.2.0, stripped
        eltex-pg2-v26@eltex~$ 




### 15. Установите, к какому типу относятся файлы /boot/initrd.img*.  

        eltex-pg2-v26@eltex~$ file /boot/initrd.img*
        /boot/initrd.img-6.1.0-27-amd64: ASCII cpio archive (SVR4 with no CRC)
        /boot/initrd.img-6.1.0-31-amd64: ASCII cpio archive (SVR4 with no CRC)
        eltex-pg2-v26@eltex~$ 

***Файлы /boot/initrd.img-* являются архивами в формате cpio***   
***cpio - означает Copy in and out (скопировать ввод и вывод). Это еще один стандартный архиватор для Linux.***  


