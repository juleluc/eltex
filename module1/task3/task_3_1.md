## Задания. Раздел 1
### 1.Войдите под пользователем user1 из практики 2 (su - user1)  
    root@eltex-practice2-pg2-v26:~ # su - user1
    user1@eltex-practice2-pg2-v26:~$ 

### 2.Подсчитайте количество процессов, имеющих несколько потоков выполнения  
`-L - отображать потоки процессов в колонках LWP и NLWP;`  
`-o - позволяет определить свой формат вывода;`  
`-e - выбрать все процессы;`  
`nlwp — это имя поля, которое указывает на количество потоков у процесса.`  

    user1@eltex-practice2-pg2-v26:~$ ps -eo nlwp | awk '$1 > 1 {count++} END {print count}'
    11
    user1@eltex-practice2-pg2-v26:~$

### 3.Запустите top и настройте вывод полей с информацией о процессе следующим образом:
`• удалите поля VIRT, RES, SHR;`  
`• добавьте поле RUSER и сделайте так, чтобы это поле было показано после поля USER;`  

`f войти в режим настройки полей.`  

    top - 13:59:25 up 11:44,  1 user,  load average: 0.00, 0.00, 0.00
    Tasks: 107 total,   1 running, 106 sleeping,   0 stopped,   0 zombie
    %Cpu(s):  0.2 us,  0.0 sy,  0.0 ni, 99.8 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st 
    MiB Mem :   3916.0 total,   3133.1 free,    447.9 used,    563.3 buff/cache     
    MiB Swap:   3185.0 total,   3185.0 free,      0.0 used.   3468.1 avail Mem 

    PID USER     RUSER     PR  NI S  %CPU  %MEM     TIME+ COMMAND                                                                                            
      1 root     root      20   0 S   0.0   0.3   0:01.21 systemd                                                                                            
      2 root     root      20   0 S   0.0   0.0   0:00.00 kthreadd                                                                                           
      3 root     root      20   0 S   0.0   0.0   0:00.00 pool_workqueue_release                                                                             
      4 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-rcu_g                                                                                    
      5 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-rcu_p                                                                                    
      6 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-slub_                                                                                    
      7 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-netns                                                                                    
     10 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/0:0H-events_highpri                                                                        
     12 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-mm_pe                                                                                    
     13 root     root      20   0 I   0.0   0.0   0:00.00 rcu_tasks_kthread                                                                                  
     14 root     root      20   0 I   0.0   0.0   0:00.00 rcu_tasks_rude_kthread                                                                             
     15 root     root      20   0 I   0.0   0.0   0:00.00 rcu_tasks_trace_kthread                                                                            
     16 root     root      20   0 S   0.0   0.0   0:00.01 ksoftirqd/0                                                                                        
     17 root     root      20   0 I   0.0   0.0   0:00.31 rcu_preempt                                                                                        
     18 root     root      rt   0 S   0.0   0.0   0:00.13 migration/0                                                                                        
     19 root     root     -51   0 S   0.0   0.0   0:00.00 idle_inject/0                                                                                      
     20 root     root      20   0 S   0.0   0.0   0:00.00 cpuhp/0                                                                                            
     21 root     root      20   0 S   0.0   0.0   0:00.00 cpuhp/1                                                                                            
     22 root     root     -51   0 S   0.0   0.0   0:00.00 idle_inject/1                                                                                      
     23 root     root      rt   0 S   0.0   0.0   0:00.42 migration/1                                                                                        
     24 root     root      20   0 S   0.0   0.0   0:00.01 ksoftirqd/1                                                                                        
     26 root     root       0 -20 I   0.0   0.0   0:00.06 kworker/1:0H-kblockd                                                                               
     27 root     root      20   0 S   0.0   0.0   0:00.00 kdevtmpfs                                                                                          
     28 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-inet_                                                                                    
     30 root     root      20   0 S   0.0   0.0   0:00.00 kauditd                                                                                            
     31 root     root      20   0 S   0.0   0.0   0:00.00 khungtaskd                                                                                         
     32 root     root      20   0 S   0.0   0.0   0:00.00 oom_reaper                                                                                         
     33 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-write                                                                                    
     34 root     root      20   0 S   0.0   0.0   0:00.85 kcompactd0                                                                                         
     36 root     root      25   5 S   0.0   0.0   0:00.00 ksmd                                                                                               
     37 root     root      39  19 S   0.0   0.0   0:00.00 khugepaged                                                                                         
     38 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-kinte                                                                                    
     39 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-kbloc                                                                                    
     40 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-blkcg                                                                                    
     41 root     root     -51   0 S   0.0   0.0   0:00.00 irq/9-acpi                                                                                         
     42 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-tpm_d                                                                                    
     43 root     root       0 -20 I   0.0   0.0   0:00.00 kworker/R-ata_s  

### 4.В другом терминальном окне выполните команду passwd и оставьте ее в состоянии запроса текущего пароля  
    user1@eltex-practice2-pg2-v26:~$ passwd
    Changing password for user1.
    Current password: 

### 5. Перейдите в терминальное окно с top и выполните следующие действия:
`• выведите все процессы, для которых реальным пользователем является пользователь, которым вы вошли в сеанс;`   
`• найдите процесс, запущенный командой passwd;`  
`• отправьте этому процессу сигналы 15 (SIGTERM), 2 (SIGINT), 3 (SIGQUIT), 9(SIGKILL)`  

    Tasks: 113 total,   1 running, 112 sleeping,   0 stopped,   0 zombie
    %Cpu(s):  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st 
    MiB Mem :   3916.0 total,   3106.7 free,    453.5 used,    584.3 buff/cache     
    MiB Swap:   3185.0 total,   3185.0 free,      0.0 used.   3462.5 avail Mem 
        PID USER     RUSER     PR  NI S  %CPU  %MEM     TIME+ COMMAND                                                                                            
    2962 root     root      20   0 I   0.0   0.0   0:00.07 kworker/u4:1-events_unbound                                                                        
    2996 root     root      20   0 I   0.0   0.0   0:00.10 kworker/0:1-events                                                                                 
    3003 root     root      20   0 I   0.0   0.0   0:00.06 kworker/u4:0-events_power_efficient                                                                
    3021 root     root      20   0 I   0.0   0.0   0:00.00 kworker/0:2                                                                                        
    3330 root     root      20   0 I   0.0   0.0   0:00.01 kworker/u4:2-events_unbound                                                                        
    3331 root     root      20   0 S   0.0   0.2   0:00.00 sshd                                                                                               
    3429 root     root      20   0 S   0.0   0.1   0:00.00 bash                                                                                               
    3440 root     root      20   0 S   0.0   0.1   0:00.00 su                                                                                                 
    3450 root     user1     20   0 S   0.0   0.1   0:00.00 passwd   

Отправляем сигналы  процессу 3450(passwd).  

    user1@eltex-practice2-pg2-v26:~$ kill -15 3450
    user1@eltex-practice2-pg2-v26:~$ kill -2 3450
    user1@eltex-practice2-pg2-v26:~$ kill -3 3450
    user1@eltex-practice2-pg2-v26:~$ kill -9 3450
    user1@eltex-practice2-pg2-v26:~$ 

Другое терминально окно:  

    user1@eltex-practice2-pg2-v26:~$ passwd
    Changing password for user1.
    Current password: Killed
    user1@eltex-practice2-pg2-v26:~$ 

После отправки сигнала 9 процесс passwd был завершен.  

### 6.Выполните команду vim ~/file_task3.txt и нажмите Ctrl-Z
    user1@eltex-practice2-pg2-v26:~$ vim ~/file_task3.txt
    [1]+  Stopped                 vim ~/file_task3.txt
    user1@eltex-practice2-pg2-v26:~$ 

### 7.Выполните команду sleep 600, нажмите Ctrl-Z и выполните команду jobs
    user1@eltex-practice2-pg2-v26:~$ sleep 600
    ^Z
    [2]+  Stopped                 sleep 600
    user1@eltex-practice2-pg2-v26:~$ jobs
    [1]-  Stopped                 vim ~/file_task3.txt
    [2]+  Stopped                 sleep 600
    user1@eltex-practice2-pg2-v26:~$ 

### 8.Последнее задание (sleep 600) сделайте фоновым
    user1@eltex-practice2-pg2-v26:~$ sleep 600&
    [3] 3488
    user1@eltex-practice2-pg2-v26:~$ 

### 9.Измените число NICE у задания (sleep 600), сделав его равным 10
    user1@eltex-practice2-pg2-v26:~$ jobs -l
    [1]-  3477 Stopped                 vim ~/file_task3.txt
    [2]+  3486 Stopped                 sleep 600
    [3]   3488 Running                 sleep 600 &
    user1@eltex-practice2-pg2-v26:~$ renice 10 -p 3488
    3488 (process ID) old priority 0, new priority 10
    user1@eltex-practice2-pg2-v26:~$ 
### 10.Проверьте, что число NICE у этого задания изменилось

    Tasks: 117 total,   1 running, 114 sleeping,   2 stopped,   0 zombie
    %Cpu(s):  0.0 us,  0.2 sy,  0.0 ni, 99.8 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st 
    MiB Mem :   3916.0 total,   3090.8 free,    460.8 used,    592.8 buff/cache     
    MiB Swap:   3185.0 total,   3185.0 free,      0.0 used.   3455.2 avail Mem 
        PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND                             
    2946 user1     20   0    9176   6016   3840 S   0.0   0.2   0:01.17 bash                                
    3441 user1     20   0    8776   5504   3840 S   0.0   0.1   0:00.01 bash                                
    3477 user1     20   0   24788  13184   7936 T   0.0   0.3   0:00.01 vim                                 
    3481 user1     20   0    7188   4096   3072 S   0.0   0.1   0:00.00 nano                                
    3486 user1     20   0    5684   2048   2048 T   0.0   0.1   0:00.00 sleep                               
    3488 user1     30  10    5684   2048   2048 S   0.0   0.1   0:00.00 sleep  

### 11.Сделайте задание vim ~/file_ task3.txt активным и выйдите из редактора
    user1@eltex-practice2-pg2-v26:~$ jobs
    [1]-  Stopped                 vim ~/file_task3.txt
    [2]+  Stopped                 sleep 600
    [3]   Running                 sleep 600 &
    user1@eltex-practice2-pg2-v26:~$ fg %1
    vim ~/file_task3.txt
    user1@eltex-practice2-pg2-v26:~$ 

### 12.Отправьте сигнал 15 (SIGTERM) заданию sleep 600 и выполните команду jobs
    user1@eltex-practice2-pg2-v26:~$ jobs -l
    [2]+  3486 Stopped                 sleep 600
    [3]-  3488 Running                 sleep 600 &
    user1@eltex-practice2-pg2-v26:~$ kill -15 3488
    user1@eltex-practice2-pg2-v26:~$ jobs -l
    [2]+  3486 Stopped                 sleep 600
    [3]-  3488 Terminated              sleep 600
    user1@eltex-practice2-pg2-v26:~$ 

### 13.Создайте перехватчик сигналов SIGINT и SIGQUIT внутри командного интерпретатора, который выводит сообщение «Меня голыми руками не возьмёшь!» (используйте встроенную команду trap) и отправьте сигналы самому себе  
`Отправляем сигнал SIGINT и SIGQUIT: Ctrl+c и Ctrl+\ в терминале.` 
 
    user1@eltex-practice2-pg2-v26:~$ trap 'echo "Меня голыми руками не возьмёшь!"' SIGINT SIGQUIT
    Меня голыми руками не возьмёшь!$ ^C

    Меня голыми руками не возьмёшь!$ ^\
    Меня голыми руками не возьмёшь!  ^C

    user1@eltex-practice2-pg2-v26:~$ 






