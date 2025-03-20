

## Задания. Раздел 1

 ### 1. Подключитесь к серверу для выполнения практических работ, используя клиент для протокола ssh: ssh, putty, smartty (попробуйте их все и остановитесь на наиболее удобном для вас).
 Для подключения к серверу используется команда:
 - ssh eltex-pg2-v26@217.71.138.1 -p 44555

 ### 2.Запустите новую сессию утилиты screen, с именем по умолчанию, посмотрите список подключенных пользователей командой w, отключитесь от сессии.
1. Запуск новой сессию: screen  
2. Просмотр списка подключенных пользователей с помощью команды w:  

eltex-pg2-v26@eltex:~$ w  

22:44:06 up 7 days, 31 min, 10 users, load average: 0,07, 0,03, 0,01  

| USER      | TTY   | FROM               | LOGIN@   | IDLE    | JCPU   | PCPU   | WHAT                                              |
|-----------|-------|--------------------|----------|---------|--------|--------|---------------------------------------------------|
| tech      | pts/0 | 37.193.179.176     | 12мар25  | 3days   | 0.63s  | 0.14s  | sshd: tech [priv]                                 |
| eltex-pg  | pts/2 | 90.189.209.81      | 21:46    | 2:22    | 0.22s  | 0.17s  | ssh -i /home/eltex-pg1-v10/.ssh/id_rsa root@...  |
| eltex-pg  | pts/22| :pts/38:S.1        | 22:00    | 5:19    | 0.10s  | 0.10s  | ssh -l root 172.16.9.208                         |
| eltex-pg  | pts/25| 95.191.197.127     | 12:55    | 2:45m   | 1.16s  | 1.16s  | ssh root@172.16.9.195                            |
| eltex-pg  | pts/30| :pts/35:S.0        | 22:38    | 7.00s   | 0.01s  | 0.01s  | w                                                |
| eltex-pg  | pts/35| 95.191.209.102     | 21:03    | 7.00s   | 0.02s  | ?      | screen                                           |
| eltex-pg  | pts/38| 5.137.160.45       | 21:52    | 7.00s   | 0.01s  | ?      | screen -S eltex-pg2-v8_part2                     |
| eltex-pg  | pts/43| :pts/38:S.0        | 22:00    | 7.00s   | 0.48s  | 0.48s  | ssh -l root 172.16.9.208                         |
| eltex-pg  | pts/42| :pts/32:S.0        | 13мар25  | 6days   | 0.00s  | ?      | SCREEN -dmS TEST2                                |
| eltex-pg  | pts/47| 92.127.232.89      | 22:41    | 1:55    | 0.08s  | 0.08s  | ssh root@172.16.9.206                            |

3. Отключение от сессии:  
   Ctrl+A, затем D  


 ### 3. Запустите отсоединенную сессию утилиты screen, при этом запустите в этой сессии команду top. Назовите сессию именем «top».
1. Просмотр списка сессий:  

        eltex-pg2-v26@eltex:~$ screen -ls  
        There are screens on:  

                1127405.pts-35.eltex    (19.03.2025 23:28:56)   (Detached)  

        1 Sockets in /run/screen/S-eltex-pg2-v26.  

2. Подключение к сессии:  

        eltex-pg2-v26@eltex:~$ screen -r 1127405  
        eltex-pg2-v26@eltex:~$ screen -ls  

        There are screens on:  

                1127405.pts-35.eltex    (19.03.2025 23:28:56)   (Attached)  

        1 Sockets in /run/screen/S-eltex-pg2-v26.  

        eltex-pg2-v26@eltex:~$   

3. Запуск команды top.  

4. Создание новой сессии с именем top:  

eltex-pg2-v26@eltex:~$ screen -S top -d -m  

 ### 4. Получите список сессий, созданных утилитой screen.  
        eltex-pg2-v26@eltex:~$ screen -ls  

        There are screens on:  

                1132825.top     (19.03.2025 23:57:18)   (Detached)  

                1127405.pts-35.eltex    (19.03.2025 23:28:56)   (Attached)  

        2 Sockets in /run/screen/S-eltex-pg2-v26.  

 ### 5. Подсоединитесь к сессии top.  

        eltex-pg2-v26@eltex:~$ screen -r top  

        eltex-pg2-v26@eltex:~$ screen -ls  

        There are screens on:  

                1132825.top     (19.03.2025 23:57:18)   (Attached)  

                1127405.pts-35.eltex    (19.03.2025 23:28:56)   (Attached)  

        2 Sockets in /run/screen/S-eltex-pg2-v26.  

        eltex-pg2-v26@eltex:~$   
 ### 6. Создайте еще одно окно в сессии top.  

Ctrl-a c - создать новое окно  

 ###  7. В созданном окне выполните команду: watch /usr/bin/vmstat 
1. Выполнение команды: watch /usr/bin/vmstat 

Every 2,0s: /usr/bin/vmstat  
eltex: Thu Mar 20 00:04:14 2025  

| procs | -----------memory---------- | ---swap-- | -----io---- | -system-- | ------cpu------ |
|-------|----------------------------|-----------|-------------|-----------|-----------------|
| r     | swpd   free   buff  cache  | si   so   | bi    bo    | in   cs   | us   sy   id   wa   st |
| 2     | 0      2466276 151560 932032 | 0    0    | 0     1     | 68   119  | 0    0    100  0    0 |

 ###  9. Получите список окон.
Ctrl-a " - список окон;

|Num |Name |Flags|
|----|-----|-----|
|0   |bash |$    |
|1   |bash |$    |

 ### 10.Переименуйте второе окно как «vmstat».
Ctrl-a A - изменить название окно.
|Num |Name |Flags|
|----|-----|-----|
|0   |bash |$    |
|1   |vmstat |$    |
 ###  11.Перейдите в окно, в котором работает top.
Ctrl-a n - переход в следующее окно; 
 ###  12.Отсоединитесь от сессии top.
Ctrl-a d - отсоединиться от текущей сессии;
    ```
        [detached from 1132825.top]

        eltex-pg2-v26@eltex:~$ screen -ls

        There are screens on:

            1132825.top	(19.03.2025 23:57:18)	(Detached)

            1127405.pts-35.eltex	(19.03.2025 23:28:56)	(Attached)

        2 Sockets in /run/screen/S-eltex-pg2-v26.

        eltex-pg2-v26@eltex:~$ ...

 ###  13.Запустите новую сессию и запустите в окне команду: vi report_part1.txt
Вводим screen
Проверяем что новая сессия создалась 
eltex-pg2-v26@eltex:~$ screen -ls

There are screens on:

        1136954.pts-51.eltex    (20.03.2025 00:18:34)   (Attached)

        1132825.top     (19.03.2025 23:57:18)   (Detached)

        1127405.pts-35.eltex    (19.03.2025 23:28:56)   (Attached)

3 Sockets in /run/screen/S-eltex-pg2-v26.

eltex-pg2-v26@eltex:~$ 

Запускаем команду vi report_part1.txt
 ### 14.Отсоединитесь от сессии и получите список сессий.
Ctrl-a d - отсоединиться от текущей сессии;
        [detached from 1136954.pts-51.eltex]

        eltex-pg2-v26@eltex:~$ screen -ls

        There are screens on:

            1136954.pts-51.eltex	(20.03.2025 00:18:34)	(Detached)

            1132825.top	(19.03.2025 23:57:18)	(Detached)

            1127405.pts-35.eltex	(19.03.2025 23:28:56)	(Attached)

        3 Sockets in /run/screen/S-eltex-pg2-v26.

        eltex-pg2-v26@eltex:~$ 

 ### 15.Отключитесь от сервера, используя команду logout или комбинацию клавиш Ctrl+D
        eltex-pg2-v26@eltex:~$ 

        logout

        Connection to 217.71.138.1 closed.

        vboxuser@ubuntu:~$ 

 ### 16.Подключитесь к серверу (как в п.1), и получите список сессий screen
        vboxuser@ubuntu:~$ ssh eltex-pg2-v26@217.71.138.1 -p 44555

        eltex-pg2-v26@217.71.138.1's password: 

        Linux eltex 6.1.0-31-amd64 #1 SMP PREEMPT_DYNAMIC Debian 6.1.128-1 (2025-02-07) x86_64



        The programs included with the Debian GNU/Linux system are free software;

        the exact distribution terms for each program are described in the

        individual files in /usr/share/doc/*/copyright.



        Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent

        permitted by applicable law.

        Last login: Wed Mar 19 23:34:53 2025 from 95.191.209.102

    ```
            eltex-pg2-v26@eltex:~$ screen -ls

            There are screens on:

                    1136954.pts-51.eltex    (20.03.2025 00:18:34)   (Detached)

                    1132825.top     (19.03.2025 23:57:18)   (Detached)

                    1127405.pts-35.eltex    (19.03.2025 23:28:56)   (Attached)

            3 Sockets in /run/screen/S-eltex-pg2-v26.

        eltex-pg2-v26@eltex:~$ 


 ### 17. Подключитесь к сессии с редактором и запишите в файл
    "ФИО часть 1 модуля 1 успешно завершена дата и время"  

    ```
        eltex-pg2-v26@eltex:~$ screen -r 1136954  

        "report_part1.txt" [New] 1L, 102B written

        eltex-pg2-v26@eltex:~$ cat report_part1.txt 

        Туртугешев А.В часть 1 модуля 1 успешно заверешена 06.03.2025

 ## 18 Закройте редактор, сохранив файл и закройте все сессии screen.
    eltex-pg2-v26@eltex:~$ screen -ls

    There are screens on:

        1136954.pts-51.eltex	(20.03.2025 00:18:34)	(Attached)

        1132825.top	(19.03.2025 23:57:18)	(Detached)

        1127405.pts-35.eltex	(19.03.2025 23:28:56)	(Detached)

    3 Sockets in /run/screen/S-eltex-pg2-v26.

Вводим Ctr-a d или exit

