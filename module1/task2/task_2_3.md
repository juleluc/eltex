## Задания. Раздел 3
Лог работы – команды и результаты в записать в файл practice2_part3.log
### 1.Зарегистрируйтесь на сайте github.com, если еще не сделали этого ранее  
### 2.Установите параметры git в соответствии с вашими учетными данными:  

`git config --global user.name "имя пользователя github"`  
`git config --global user.email "ваш e-mail, использованный при регистрации"`  
`git config --global init.defaultBranch main`  

    vboxuser@ubuntu:~/ELTEX$ script practice2_part3.log
    Script started, output log file is 'practice2_part3.log'.
    vboxuser@ubuntu:~/ELTEX$ git config --global user.name "juleluc"
    vboxuser@ubuntu:~/ELTEX$ git config --global user.email "aleksey08.tg@gmail.com"
    vboxuser@ubuntu:~/ELTEX$ git config --global init.defaultBranch main
### 3.Установите непосредственно программу git и набор утилит для управления github из командной строки
  `gh:`  
  `apt update`  
  `apt install git gh`  

***apt update*** 

    vboxuser@ubuntu:~/ELTEX$ sudo apt update
    [sudo] password for vboxuser: 
    Hit:1 http://ru.archive.ubuntu.com/ubuntu jammy InRelease
    Get:2 http://ru.archive.ubuntu.com/ubuntu jammy-updates InRelease [128 kB]
    Get:4 http://ru.archive.ubuntu.com/ubuntu jammy-backports InRelease [127 kB]   
    Hit:5 http://security.ubuntu.com/ubuntu jammy-security InRelease
    Hit:3 https://packages.microsoft.com/repos/code stable InRelease
    Hit:6 https://ppa.launchpadcontent.net/gns3/ppa/ubuntu jammy InRelease
    Get:7 http://ru.archive.ubuntu.com/ubuntu jammy-updates/main amd64 DEP-11 Metadata [103 kB]
    Get:8 http://ru.archive.ubuntu.com/ubuntu jammy-updates/restricted amd64 DEP-11 Metadata [212 B]
    Get:9 http://ru.archive.ubuntu.com/ubuntu jammy-updates/universe amd64 DEP-11 Metadata [359 kB]
    Get:10 http://ru.archive.ubuntu.com/ubuntu jammy-updates/multiverse amd64 DEP-11 Metadata [940 B]
    Get:11 http://ru.archive.ubuntu.com/ubuntu jammy-backports/main amd64 DEP-11 Metadata [7 028 B]
    Get:12 http://ru.archive.ubuntu.com/ubuntu jammy-backports/restricted amd64 DEP-11 Metadata [212 B]
    Get:13 http://ru.archive.ubuntu.com/ubuntu jammy-backports/universe amd64 DEP-11 Metadata [17,7 kB]
    Get:14 http://ru.archive.ubuntu.com/ubuntu jammy-backports/multiverse amd64 DEP-11 Metadata [212 B]
    Fetched 744 kB in 4s (192 kB/s)          
    Reading package lists... Done
    Building dependency tree... Done
    Reading state information... Done
    148 packages can be upgraded. Run 'apt list --upgradable' to see them.  

***apt install git gh***  

    vboxuser@ubuntu:~/ELTEX$ sudo apt install git gh
    Reading package lists... Done
    Building dependency tree... Done
    Reading state information... Done
    git is already the newest version (1:2.34.1-1ubuntu1.12).
    The following NEW packages will be installed:
      gh
    0 upgraded, 1 newly installed, 0 to remove and 148 not upgraded.
    Need to get 6 242 kB of archives.
    After this operation, 33,7 MB of additional disk space will be used.
    Do you want to continue? [Y/n] y
    Get:1 http://ru.archive.ubuntu.com/ubuntu jammy/universe amd64 gh amd64 2.4.0+dfsg1-2 [6 242 kB]
    Fetched 6 242 kB in 1s (4 205 kB/s) 
    Selecting previously unselected package gh.
    (Reading database ... 251372 files and directories currently installed.)
    Preparing to unpack .../gh_2.4.0+dfsg1-2_amd64.deb ...
    Unpacking gh (2.4.0+dfsg1-2) ...
    Setting up gh (2.4.0+dfsg1-2) ...
    Processing triggers for man-db (2.10.2-1) ...

### 4.Создайте ключ ssh:
`ssh-keygen -t ed25519 -f ~/.ssh/название_ключа (имя пользователя github или имя пользователя для первой практики, или на ваш вкус)`  

    vboxuser@ubuntu:~/ELTEX$ ssh-keygen -t ed25519 -f ~/.ssh/juleluc
    Generating public/private ed25519 key pair.
    Enter passphrase (empty for no passphrase): 
    Enter same passphrase again: 
    Your identification has been saved in /home/vboxuser/.ssh/juleluc
    Your public key has been saved in /home/vboxuser/.ssh/juleluc.pub
    The key fingerprint is:
    SHA256:HQpfW43LmZFhTwOEptacap+oTXs1oBWYyJ1EdG7RdNc vboxuser@ubuntu
    The key's randomart image is:
    +--[ED25519 256]--+
    |     . *++o=*.+ o|
    |      o =o+o.O oE|
    |      .  ==o= o  |
    |       oo=*= =   |
    |       .S+o.=    |
    |        +   o    |
    |       ..o o .   |
    |       o..+      |
    |      ..o.       |
    +----[SHA256]-----+

### 5.Подключите этот комьютер к github: gh auth login  

    vboxuser@ubuntu:~/ELTEX$ gh auth login
    ? What account do you want to log into? GitHub.com
    ? What is your preferred protocol for Git operations? SSH
    ? Upload your SSH public key to your GitHub account? /home/vboxuser/.ssh/juleluc.pub
    ? How would you like to authenticate GitHub CLI? Login with a web browser
    ! First copy your one-time code: 12F0-5128
    - Press Enter to open github.com in your browser... 
    Gtk-Message: 22:00:02.301: Not loading module "atk-bridge": The functionality is provided by GTK natively. Please try to not load it.
    ✓ Authentication complete. Press Enter to continue...
    - gh config set -h github.com git_protocol ssh
    ✓ Configured git protocol
    ✓ Uploaded the SSH key to your GitHub account: /home/vboxuser/.ssh/juleluc.pub
    ✓ Logged in as juleluc


### 6.Укажите автоматическую авторизацию только для сайта github.com: gh auth setup-git --hostname github.com  

    vboxuser@ubuntu:~/ELTEX$ gh auth setup-git --hostname github.com
### 7.Убедиться, что все в порядке можно командой: gh auth status  

    vboxuser@ubuntu:~/ELTEX$ gh auth status
    github.com
      ✓ Logged in to github.com as juleluc (/home/vboxuser/.config/gh/hosts.yml)
      ✓ Git operations for github.com configured to use ssh protocol.
      ✓ Token: *******************

### 8.Создайте репозиторий на сервере github: gh repo create --public название_репозитория  

    vboxuser@ubuntu:~/ELTEX$ gh repo create --public eltex  
    ✓ Created repository juleluc/eltex on GitHub  

### 9.Пора наполнить его:  

`mkdir ~/название_репозитория && cd ~/название_репозитория`  
`echo "# краткое_описание_репозитория" >> README.md`  
`git init`  
`git add README.md`  
`git commit -m "first commit"`  
`git branch -M main`  
`git remote add origin https://github.com/имя_пользователя_github/название_репозитория.git`  
`git status`  
`git push -u origin main`  
`mkdir -p module1/task1`  
`mkdir module1/task2`  
`mkdir module1/task3`  
`(скопируйте с сервера для 1 практики отчеты в каталоги task* используя команду scp)`    
`git add .`  
`git status`  
`git commit (введите комментарий)`  
`git push`  

---  

    vboxuser@ubuntu:~/ELTEX$ mkdir ~/eltex && cd ~/eltex

    vboxuser@ubuntu:~/eltex$ echo "#Проекты школы программирования от компании ELTEX" >> README.md

    vboxuser@ubuntu:~/eltex$ git init
    Initialized empty Git repository in /home/vboxuser/eltex/.git/

    vboxuser@ubuntu:~/eltex$ git add README.md

    vboxuser@ubuntu:~/eltex$ git commit -m "first commit"
    [main (root-commit) fd66b2e] first commit
    1 file changed, 1 insertion(+)
    create mode 100644 README.md

    vboxuser@ubuntu:~/eltex$ git branch -M main

    vboxuser@ubuntu:~/eltex$ git remote add origin https://github.com/juleluc/eltex.git

    vboxuser@ubuntu:~/eltex$ git push -u origin main
    Enumerating objects: 3, done.
    Counting objects: 100% (3/3), done.
    Delta compression using up to 6 threads
    Compressing objects: 100% (2/2), done.
    Writing objects: 100% (3/3), 283 bytes | 283.00 KiB/s, done.
    Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
    To https://github.com/juleluc/eltex.git
    * [new branch]      main -> main
    Branch 'main' set up to track remote branch 'main' from 'origin'.

    vboxuser@ubuntu:~/eltex$ mkdir -p module1/task1

    vboxuser@ubuntu:~/eltex$ mkdir module1/task2

    vboxuser@ubuntu:~/eltex$ mkdir module1/task3

***скопируйте с сервера для 1 практики отчеты в каталоги task* используя команду scp***  

    vboxuser@ubuntu:~/eltex$ scp -P 44555 eltex-pg2-v26@217.71.138.1:/home/eltex-pg2-v26/task_1_1.md ~/eltex/module1/task1/
    eltex-pg2-v26@217.71.138.1's password: 
    task_1_1.md                                   100% 9680   137.3KB/s   00:00    

    vboxuser@ubuntu:~/eltex$ git add .

    vboxuser@ubuntu:~/eltex$ git status
    On branch main
    Your branch is up to date with 'origin/main'.
    Changes to be committed:
      (use "git restore --staged <file>..." to unstage)
      new file:   module1/task1/task_1_1.md

    vboxuser@ubuntu:~/eltex$ git commit -m "Добавлен файл task_1_1.md"
    [main 823cdaa] Добавлен файл task_1_1.md
    1 file changed, 247 insertions(+)
    create mode 100644 module1/task1/task_1_1.md

    vboxuser@ubuntu:~/eltex$ git push
    Enumerating objects: 6, done.
    Counting objects: 100% (6/6), done.
    Delta compression using up to 6 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (5/5), 3.14 KiB | 3.14 MiB/s, done.
    Total 5 (delta 0), reused 0 (delta 0), pack-reused 0
    To https://github.com/juleluc/eltex.git
      fd66b2e..823cdaa  main -> main


### 10.Клонируйте ваш репозиторий: mkdir ~/название_репозитория_clone && cd ~/название_репозитория_clone git clone https://github.com/имя_пользователя_github/название_репозитория.git . (nb! точка)  

    vboxuser@ubuntu:~/eltex$ mkdir ~/eltex_clone && cd ~/eltex_clone
    vboxuser@ubuntu:~/eltex_clone$ git clone https://github.com/juleluc/eltex.git .

    Cloning into '.'...
    remote: Enumerating objects: 8, done.
    remote: Counting objects: 100% (8/8), done.
    remote: Compressing objects: 100% (5/5), done.
    remote: Total 8 (delta 0), reused 8 (delta 0), pack-reused 0 (from 0)
    Receiving objects: 100% (8/8), done.

### 11.Внесите изменение в основном каталоге, не забыв про git add/commit/push, выполните в каталоге с клоном:  
`git fetch`  
`git log origin/main`  
`git diff main origin/main`  
`git merge (для автоматического слияния используйте git pull вместо fetch+merge)`  

    vboxuser@ubuntu:~/eltex_clone$ echo "Изменение в клоне репозитория" >> README.mdvboxuser@ubuntu:~/eltex_clone$ git add README.md
    vboxuser@ubuntu:~/eltex_clone$ git commit -m "Внесено изменение в клонированном репозитории"
    [main 8716b02] Внесено изменение в клонированном репозитории
    1 file changed, 1 insertion(+)

    vboxuser@ubuntu:~/eltex_clone$ git push
    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Delta compression using up to 6 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 446 bytes | 446.00 KiB/s, done.
    Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
    To https://github.com/juleluc/eltex.git
      823cdaa..8716b02  main -> main

    vboxuser@ubuntu:~/eltex_clone$ git fetch

    vboxuser@ubuntu:~/eltex_clone$ git log origin/main
    commit 8716b02f2db031cb4a59add82f10c22f63d2e9cb (HEAD -> main, origin/main, origin/HEAD)
    Author: juleluc <aleksey08.tg@gmail.com>
    Date:   Thu Mar 20 13:40:27 2025 +0700
        Внесено изменение в клонированном репозитории

    commit 823cdaafce66e663258bf38bf68883f4cc6826b5
    Author: juleluc <aleksey08.tg@gmail.com>
    Date:   Thu Mar 20 13:34:45 2025 +0700
        Добавлен файл task_1_1.md

    commit fd66b2ea213993a921f7e177120cd5c55b30e466
    Author: juleluc <aleksey08.tg@gmail.com>
    Date:   Wed Mar 19 22:17:53 2025 +0700
        first commit

    vboxuser@ubuntu:~/eltex_clone$ git diff main origin/main

    vboxuser@ubuntu:~/eltex_clone$ git merge origin/main
    Already up to date.

    vboxuser@ubuntu:~/eltex_clone$ git pull
    Already up to date.
    vboxuser@ubuntu:~/eltex_clone$ 







