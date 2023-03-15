github-repo with sources,files,projects for MPU-w-H3-in-MPLABX session 
 for ESI-F2Fww seminar in spring-2023

History: 
    v1.0: (SL, 15.3.2023)
    First repo version with all projects working
          Projects are:
            f2fL1_sam9x60   = simple blinkyLED+UARTout for SAM9x60-curiosity
            f2fL1_sama7ek   = simple blinkyLED+UARTout for SAMA7G5-EK
            f2fL2_at91      = only links to used H3-csp projects for at91*.X
            f2fL3_usb       = existing H3-usb-prj with self-created at91
            LabHelp         = support-files for labs
          
          PPT: 0-F2F_ESIww_MPUsession.pptx

Steps to create this github-repo:
-) all H3-prj and slides are pre-created and stored in 
    '<path>\gh_esi_f2f_ww_2023\'
-) create github-repo 'mpu_w_h3_in_mplabx' online with:
    -) enter github -> login to stefanluethin-microchip
    -) select 'Repositories' and 'new' and name it 'mpu_w_h3_in_mplabx'
-) locally in gitbash:
    ()> cd <path>\gh_esi_f2f_ww_2023\
    (gh_esi_f2f_ww_2023\)> git init
    (gh_esi_f2f_ww_2023\)> git add *
    (gh_esi_f2f_ww_2023\)> git commit -m "first commit"
    (gh_esi_f2f_ww_2023\)> git branch
        * master
     #-make sure branch is called 'master' not 'main' 
     #- -> rule?!? at least the H3-repo all use 'master'
     #-If name is different, before you push, rename branch with
    (gh_esi_f2f_ww_2023\)> git branch -M master

    (gh_esi_f2f_ww_2023\)> git remote add origin https://github.com/stefanluethin-microchip/mpu_w_h3_in_mplabx.git^
    (gh_esi_f2f_ww_2023\)> git push -u origin master
        Enumerating objects: 1452, done.
        Counting objects: 100% (1452/1452), done.
        Delta compression using up to 12 threads
        Compressing objects: 100% (1420/1420), done.
        Writing objects: 100% (1452/1452), 22.78 MiB | 5.03 MiB/s, done.
        Total 1452 (delta 1001), reused 0 (delta 0), pack-reused 0
        remote: Resolving deltas: 100% (1001/1001), done.
        To https://github.com/stefanluethin-microchip/mpu_w_h3_in_mplabx.git
            * [new branch]      master -> master
        Branch 'master' set up to track remote branch 'master' from 'origin'.


#eof