
## Задания. Раздел 2

### 1. Запустите новую сессию с именем "пользователь в системе_part2". Все команды сохраняйте в файле $USER_part.log  

        eltex-pg2-v26@eltex:~$ screen -S пользователь\ в\ системе_part2 -d -m
        eltex-pg2-v26@eltex:~$ screen -ls
        There are screens on:

            1277350.пользователь в системе_part2	(20.03.2025 13:12:40)	(Detached)

            1136954.pts-51.eltex	(20.03.2025 00:18:34)	(Detached)

            1132825.top	(19.03.2025 23:57:18)	(Detached)

            1127405.pts-35.eltex	(19.03.2025 23:28:56)	(Detached)

        4 Sockets in /run/screen/S-eltex-pg2-v26.

***Создание лог файла***  

        eltex-pg2-v26@eltex:~$ touch ${USER}_part.log

        eltex-pg2-v26@eltex:~$ ls

        eltex-pg2-v26_part.log  report_part1.txt

### 2. С помощью механизма дополнения имен команд выведите все команды, которые начинаются на «ls».  
***Вводим команду ls и намаем клавишу tab 2 раза***  
    eltex-pg2-v26@eltex~$ ls

    ls           lsb_release  lsinitramfs  lslocks      lsmod        lspci

    lsattr       lscpu        lsipc        lslogins     lsns         lsusb

    lsblk        lsfd         lsirq        lsmem        lsof         

    eltex-pg2-v26@eltex~$
### 4. С помощью механизма дополнения имен переменных выведите все переменные, которые начинаются с «HIST».
***Аналогично с ls***  
    eltex-pg2-v26@eltex~$ echo $HIST

    $HISTCMD         $HISTFILE        $HISTSIZE        

    $HISTCONTROL     $HISTFILESIZE    $HISTTIMEFORMAT  

    eltex-pg2-v26@eltex~$ echo $HIST

***Использование команды compgen***   
 -v - список всех переменных окружения.  

    eltex-pg2-v26@eltex~$ compgen -v HIST
    HISTCMD
    HISTCONTROL
    HISTFILE
    HISTFILESIZE
    HISTSIZE
    HISTTIMEFORMAT
    eltex-pg2-v26@eltex~$ 

### 6. Узнайте, сколько команд может храниться в файле истории.
    eltex-pg2-v26@eltex~$ echo $HISTSIZE 
    1000
    eltex-pg2-v26@eltex~$ 

### 7. Выведите имена файлов и каталогов из домашнего каталога, которыеначинаются с «.».
 - флаг d отображения информации о каталоге.  

        eltex-pg2-v26@eltex~$ ls -d ~/.*
        /home/eltex-pg2-v26/.bash_history  /home/eltex-pg2-v26/.log
        /home/eltex-pg2-v26/.bash_logout   /home/eltex-pg2-v26/.profile
        /home/eltex-pg2-v26/.bashrc        /home/eltex-pg2-v26/.report_part1.txt.swo
        /home/eltex-pg2-v26/.bashrc.save   /home/eltex-pg2-v26/.report_part1.txt.swp
        /home/eltex-pg2-v26/.config        /home/eltex-pg2-v26/.ssh
        /home/eltex-pg2-v26/.lesshst       /home/eltex-pg2-v26/.viminfo
        /home/eltex-pg2-v26/.local
        eltex-pg2-v26@eltex~$ 

### 8. Настройте вывод даты выполнения команд, хранящихся в истории.
Используем переменную окружения HISTTIMEFORMAT  
%F: Формат даты в виде YYYY-MM-DD.  
%T: Формат времени в виде HH:MM:SS.  

    eltex-pg2-v26@eltex~$ export HISTTIMEFORMAT='%F %T '
    eltex-pg2-v26@eltex~$ history | tail -n 10
    416  2025-03-20 18:41:13 ls
    417  2025-03-20 18:41:20 cat eltex-pg2-v26_part.log 
    418  2025-03-20 18:42:38 nano eltex-pg2-v26_part.log 
    419  2025-03-20 18:56:48 compgen -v HIST
    420  2025-03-20 18:58:09 echo $HISTSIZE 
    421  2025-03-20 18:59:46 ls -d ~/.*
    422  2025-03-20 19:01:53 export HISTTIMEFORMAT='%F %T '
    423  2025-03-20 19:01:57 history
    424  2025-03-20 19:02:19 export HISTTIMEFORMAT='%F %T '
    425  2025-03-20 19:02:35 history | tail -n 10
    eltex-pg2-v26@eltex~$ 

### 9. Настройте автоматическое сохранение набираемых команд в файлеистории:
• введите любую команду, например, команду date;  
• проверьте, есть ли эта команда в кэше и файле истории команд;  
• определить переменную PROMPT_COMMAND так, чтобы кэш истории сохранялся в файле истории;   
• ввести любую команду и проверить, появилась ли эта команда в кэше и файле истории.  

***Смотрим кэш***    
    eltex-pg2-v26@eltex~$ history | tail -n 5

    482  2025-03-20 19:21:38 source ~/.bashrc

    483  2025-03-20 19:22:58 ls

    484  2025-03-20 19:23:02 whoami

    485  2025-03-20 19:23:04 date

    486  2025-03-20 19:23:14 history | tail -n 5

***Смотрим в файл .bash_history***    

    eltex-pg2-v26@eltex~$ tail -n 5 ~/.bash_history 
    ls
    #1742473318
    screen -ls
    #1742473324
    exit
    eltex-pg2-v26@eltex~$ 

Команды date, ls, whoami отсутствует в файле ~/.bash_history так как записи обновляются после завершения текущей сессии.    
Чтобы кэш истории сохранялся в файле необходимо добавить строку export export PROMPT_COMMAND='history -a' в файл ~/.bashrc и сохранить изменения.  

    eltex-pg2-v26@eltex~$ export PROMPT_COMMAND='history -a'
    eltex-pg2-v26@eltex~$ source ~/.bashrc
    eltex-pg2-v26@eltex~$ date
    Чт 20 мар 2025 19:29:40 +07
    eltex-pg2-v26@eltex~$ whoami
    eltex-pg2-v26
    eltex-pg2-v26@eltex~$ tail -n 4 ~/.bash_history 
    #1742473806
    tail -n 4 ~/.bash_history 
    #1742473829
    whoami
    eltex-pg2-v26@eltex~$ 

***history -a  - добавляет новые команды из текущей сессии в файл истории.***  

### 10. Создайте переменную DATE, в которую запишите текущую дату. Проверьте содержимое переменной.  
    eltex-pg2-v26@eltex~$ DATE=$(date +%Y-%m-%d)
    eltex-pg2-v26@eltex~$ echo $DATE
    2025-03-20
    eltex-pg2-v26@eltex~$ 
### 11. Создайте переменную TIME, в которую запишите текущее время. Проверьте содержимое переменной.  
    eltex-pg2-v26@eltex~$ TIME=$(date +%H:%M:%S)
    eltex-pg2-v26@eltex~$ echo $TIME
    19:38:14
    eltex-pg2-v26@eltex~$ 

### 12. Создайте переменную DATE_TIME в которую поместите значения из переменных DATE и TIME, разделенных пробелом. Проверьте содержимо переменной.  

    eltex-pg2-v26@eltex~$ DATE_TIME="$DATE $TIME"
    eltex-pg2-v26@eltex~$ echo $DATE_TIME
    2025-03-20 19:38:14
    eltex-pg2-v26@eltex~$ 
### 13. Выведите имена файлов, содержащие хотя бы одну цифру, из каталогов /bin и /sbin.  
`Find` - команда для поиска файлов и каталогов  
find /usr/bin /usr/sbin -type f -name '*[0-9]*'    
`-type f` - искать только файлы.  
`-name` - поиск файлов по имени.  
`[0-9]`: Одна цифра.  
`*` - любое количество символов.  

    /usr/bin/pygettext3.11
    /usr/bin/systemd-id128
    /usr/bin/x86_64-linux-gnu-dwp
    /usr/bin/bunzip2
    /usr/bin/x86_64-linux-gnu-gp-display-text
    /usr/bin/x86_64-linux-gnu-addr2line
    /usr/bin/py3compile
    /usr/bin/grub-syslinux2cfg
    /usr/bin/diff3
    /usr/bin/sha256sum
    /usr/sbin/dumpe2fs
    /usr/sbin/e2fsck
    /usr/sbin/e2freefrag
    /usr/sbin/e2undo
    /usr/sbin/e2scrub_all
    /usr/sbin/tune2fs
    /usr/sbin/e2image
    /usr/sbin/e4defrag
    /usr/sbin/mke2fs
    /usr/sbin/e4crypt
    /usr/sbin/killall5
    /usr/sbin/e2scrub
    /usr/sbin/resize2fs
    eltex-pg2-v26@eltex~$ 


### 14. Измените приглашение так, чтобы выводились имя хоста, имя пользователя и время: имя_пользователя@имя_хоста-HH:MM> (Используйте переменные bash и команду date)  
    eltex-pg2-v26@eltex~$ TIME=$(date +"%H:%M")
    eltex-pg2-v26@eltex~$ export PS1='\u@\h-$TIME> '
    eltex-pg2-v26@eltex-19:50> 

`\u: Имя пользователя`   
`\h: Имя хоста`  


### 15. Сделайте так, чтобы в запускаемом интерпретаторе bash выводилось приглашение, установленное в родительском интерпретаторе bash.  
    eltex-pg2-v26@eltex-19:50> echo $PS1
    \u@\h-$TIME>
    eltex-pg2-v26@eltex-19:50> export PS1
    eltex-pg2-v26@eltex-19:50> bash
    eltex-pg2-v26@eltex~$ 


### 16. Одной командной строкой создайте в домашнем каталоге подкаталоги для каждого месяца текущего года вида YYYY-MM(год реализуйте с помощью команды date и командной подстановки).  

    eltex-pg2-v26@eltex~$ mkdir $(date +"%Y")-{01..12}
    eltex-pg2-v26@eltex~$ ls
    2025-01  2025-04  2025-07  2025-10  eltex-pg2-v26_part.log
    2025-02  2025-05  2025-08  2025-11  report_part1.txt
    2025-03  2025-06  2025-09  2025-12  task_1_1.md
    eltex-pg2-v26@eltex~$ 

***{01..12}  создания последовательности чисел от 01 до 12***


