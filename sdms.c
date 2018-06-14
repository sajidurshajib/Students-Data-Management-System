#include <stdio.h>
#include <string.h>
#include <unistd.h>
void file_register(char loc_register[40], char file_register[40],char register_type[40]);
void search_file(char loc_search[40], char file_search[40],char type_search[40]);
void update_info(char loc_file[40], char update_file[40],char update_type[40]);
void delete_file(char del_loc[30],char del_file[40],char del_type[40]);

/*=========  Main function Start Here  ============*/
int main()
{
    char restartchar;
    int restart=1;
    while(restart==1){
        system("cls");

        printf("\n\t+-------------------------------------------------------+");
        printf("\n\t|                                                       |");
        printf("\n\t|    Students Data management system for University     |");
        printf("\n\t|                   Version: 1.1                        |");
        printf("\n\t|                                                       |");
        printf("\n\t|                   Developed by                        |");
        printf("\n\t|         Lead programmer : Sajidur Rahman              |");
        printf("\n\t|                                                       |");
        printf("\n\t+-------------------------------------------------------+");
        int select;
        printf("\n\n\n\n\t\t[+] Select->");
        printf("\n\t\t[1] Login as admin");
        printf("\n\t\t[2] Visit as student");
        printf("\n\n\t\t[*] input number which you want: ");
        scanf(" %d",&select);

        if(select == 1){
            char user_name[20];
            char pass_word[20];

            printf("\n\t\tUsername: ");
            scanf("%s",&user_name);

            FILE *user_user;
            user_user=fopen("admin/username.txt","r");
            char user_name_str[20];
            fgets(user_name_str,20,user_user);
            fclose(user_user);

            if(strcmp(user_name,user_name_str)==0){
                printf("\t\tPassword: ");
                scanf("%s",&pass_word);

                FILE *user_pass;
                user_pass=fopen("admin/password.txt","r");
                char user_pass_str[20];
                fgets(user_pass_str,20,user_pass);    /*Make "user_pass" to a string "user_pass_str"*/
                fclose(user_pass);

                if(strcmp(pass_word,user_pass_str)==0){
                    system("cls");
                    printf("\n\t\t+--------------------------------------+");
                    printf("\n\t\t|                                      |");
                    printf("\n\t\t|             Admin Panel              |");
                    printf("\n\t\t|                                      |");
                    printf("\n\t\t+--------------------------------------+");

                    printf("\n\n\t\t[1] Change username?");
                    printf("\n\t\t[2] Change password?");
                    printf("\n\t\t[3] Register new student.");
                    printf("\n\t\t[4] Search student by id.");
                    printf("\n\t\t[5] Update student info.");
                    printf("\n\t\t[6] Delete student's info.");

                    int admin_choice;
                    printf("\n\n\t\t[+] Chooose: ");
                    scanf("%d",&admin_choice);
                    getchar();                 /*This getchar() use for solve the scanf Enter problem*/
                    if(admin_choice==1){
                        update_info("admin/","username","\t\t[+] Write a new username: ");

                    }
                    else if(admin_choice==2){
                        update_info("admin/","password","\t\t[+] Write a new password: ");

                    }
                    else if(admin_choice==3){
                        system("cls");
                        printf("\n\t\t+--------------------------------------+");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t|         Register new student         |");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t+--------------------------------------+");
                        char id_reg[40];
                        printf("\n\n\t\t[+] Input Unique id\t\t:\t");
                        gets(id_reg);

                        file_register("name/",id_reg,"\t\t[+] Name\t\t\t:\t");
                        file_register("bloodGroup/",id_reg,"\t\t[+] Blood group\t\t\t:\t");
                        file_register("birthdate/",id_reg,"\t\t[+] Date of birth[dd/mm/yy]\t:\t");
                        file_register("address/",id_reg,"\t\t[+] Full Address\t\t:\t");
                        file_register("mobile/",id_reg,"\t\t[+] Mobile number\t\t:\t");
                        file_register("mail/",id_reg,"\t\t[+] Email address\t\t:\t");
                        file_register("detail/",id_reg,"\t\t[+] Detail comment\t\t:\t");
                        file_register("studentspass/",id_reg,"\t\t[+] Student's id-password\t:\t");
                    }
                    else if(admin_choice==4){
                        system("cls");
                        printf("\n\t\t+--------------------------------------+");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t|         Search student info          |");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t+--------------------------------------+");
                        char search_id_admin[20];
                        printf("\n\n\t\t[+] Search by id: ");
                        gets(search_id_admin);
                        printf("\n");

                        search_file("name/",search_id_admin,"\t\t[=] Name\t\t:\t");
                        search_file("bloodGroup/",search_id_admin,"\n\t\t[=] Blood group\t\t:\t");
                        search_file("birthdate/",search_id_admin,"\n\t\t[=] Date of birth\t:\t");
                        search_file("address/",search_id_admin,"\n\t\t[=] Address\t\t:\t");
                        search_file("mobile/",search_id_admin,"\n\t\t[=] Mobile\t\t:\t");
                        search_file("mail/",search_id_admin,"\n\t\t[=] Email\t\t:\t");
                        search_file("detail/",search_id_admin,"\n\t\t[=] Detail\t\t:\t");
                        search_file("studentspass/",search_id_admin,"\n\t\t[=] ID-password\t\t:\t");
                        printf("\n");
                        search_file("stdmsg/",search_id_admin,"\n\t\t[=] Student message: \t:\t");

                    }
                    else if(admin_choice==5){
                        system("cls");
                        printf("\n\t\t+--------------------------------------+");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t|         Update student info          |");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t+--------------------------------------+");
                        char search_id_update[20];
                        printf("\n\n\t\t[+] Search by id: ");
                        gets(search_id_update);
                        printf("\n");

                        search_file("name/",search_id_update,"\t\t[1] Name\t\t:\t");
                        search_file("bloodGroup/",search_id_update,"\n\t\t[2] Blood group\t\t:\t");
                        search_file("birthdate/",search_id_update,"\n\t\t[3] Date of birth\t:\t");
                        search_file("address/",search_id_update,"\n\t\t[4] Address\t\t:\t");
                        search_file("mobile/",search_id_update,"\n\t\t[5] Mobile\t\t:\t");
                        search_file("mail/",search_id_update,"\n\t\t[6] Email\t\t:\t");
                        search_file("detail/",search_id_update,"\n\t\t[7] Detail\t\t:\t");
                        search_file("studentspass/",search_id_update,"\n\t\t[8] ID-password\t\t:\t");

                        int edit_num;
                        printf("\n\n\t\t[*] Input the number for update[1 to 6]: ");
                        scanf("%d",&edit_num);
                        getchar();
                        if(edit_num==1){
                            update_info("name/",search_id_update,"\t\t[1] Name update\t:\t");
                        }
                        else if(edit_num==2){
                            update_info("bloodGroup/",search_id_update,"\t\t[2] Blood group update\t:\t");
                        }
                        else if(edit_num==3){
                            update_info("birthdate/",search_id_update,"\t\t[2] Date of birth update[d/m/y]\t:\t");
                        }
                        else if(edit_num==4){
                            update_info("address/",search_id_update,"\t\t[3] Address update\t:\t");
                        }
                        else if(edit_num==5){
                            update_info("mobile/",search_id_update,"\t\t[4] Mobile number update\t:\t");
                        }
                        else if(edit_num==6){
                            update_info("mail/",search_id_update,"\t\t[5] Email update\t:\t");
                        }
                        else if(edit_num==7){
                            update_info("detail/",search_id_update,"\t\t[5] Detail update\t:\t");
                        }
                        else if(edit_num==8){
                            update_info("studentspass/",search_id_update,"\t\t[5] ID-password\t:\t");
                        }
                        else{
                            printf("\n\t\t[-] You input wrong number to edit or update!");
                        }
                    }
                    else if(admin_choice==6){
                        system("cls");
                        printf("\n\t\t+--------------------------------------+");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t|         Delete student info          |");
                        printf("\n\t\t|                                      |");
                        printf("\n\t\t+--------------------------------------+");
                        printf("\n\n\t\t[-] Input id number which you want to delete: ");
                        char delete_id[40];
                        gets(delete_id);

                        delete_file("name/",delete_id,"Name");
                        delete_file("bloodGroup/",delete_id,"Blood group");
                        delete_file("birthdate/",delete_id,"Date of birth");
                        delete_file("address/",delete_id,"Address");
                        delete_file("mobile/",delete_id,"Mobile");
                        delete_file("mail/",delete_id,"Email");
                        delete_file("detail/",delete_id,"Detail comment");
                        delete_file("studentspass/",delete_id,"Student's password");
                        delete_file("stdmsg/",delete_id,"Student's message");

                    }
                    else{
                        printf("\n\t\t[-] Wrong number input! Restart the program and try again...");
                    }  /* admin choice else finish */

                }else{
                    printf("\n\t\t[-] Password incorrect.\n\n");  /* Password incorrect condition */
                }
            }else{
                printf("\n\t\t[-] Username incorrect.\n");  /* Username incorrect condition */
            }
        }
        else if(select == 2){
            /*
            +-------------------+
            |                   |
            |   Student panel   |
            |                   |
            +-------------------+
            */
            getchar();
            char student_id[20];
            char student_password[50];
            printf("\n\t\t[+] Your ID\t:\t");
            gets(student_id);


            char student_id_txt[30];
            sprintf(student_id_txt,"studentspass/%s.txt",student_id);

            if(access(student_id_txt,F_OK)==0){
                printf("\t\t[+] Password\t:\t");
                gets(student_password);

                FILE *student_pass;
                student_pass=fopen(student_id_txt,"r");
                char student_pass_str[30];
                fgets(student_pass_str,30,student_pass);
                fclose(student_pass);

                if(strcmp(student_password,student_pass_str)==0){
                    system("cls");
                    printf("\n\t\t\t+------------------------------+");
                    printf("\n\t\t\t|                              |");
                    printf("\n\t\t\t|        Student panel         |");
                    printf("\n\t\t\t|                              |");
                    printf("\n\t\t\t+------------------------------+\n\n");

                    search_file("name/",student_id,"\t\t[=] Name\t\t:\t");
                    search_file("bloodGroup/",student_id,"\n\t\t[=] Blood group\t\t:\t");
                    search_file("birthdate/",student_id,"\n\t\t[=] Date of birth\t:\t");
                    search_file("address/",student_id,"\n\t\t[=] Address\t\t:\t");
                    search_file("mobile/",student_id,"\n\t\t[=] Mobile\t\t:\t");
                    search_file("mail/",student_id,"\n\t\t[=] Email\t\t:\t");
                    search_file("detail/",student_id,"\n\t\t[=] Detail\t\t:\t");
                    search_file("studentspass/",student_id,"\n\t\t[=] ID-password\t\t:\t");

                    int std_ch;
                    printf("\n\n\t\t\t[#] Control panel...\n");
                    printf("\n\t\t\t[1] Send message to admin.");
                    printf("\n\t\t\t[2] Change your password.");
                    printf("\n\n\t\t\t[*] Choose your option: ");
                    scanf("%d",&std_ch);
                    getchar();
                    if(std_ch==1){
                        char out_msg[30];
                        sprintf(out_msg,"stdmsg/%s.txt",student_id);
                        if(access(out_msg,F_OK)==0){
                            FILE *fmsg;
                            fmsg=fopen(out_msg,"r");
                            char msg_str[300];
                            fgets(msg_str,300,fmsg);
                            fclose(fmsg);
                            printf("\n\n\t\t[+] Your previous message: %s",msg_str);
                            printf("\n\t\t[-] Your previous message will be deleted if you send new message. :)");
                        }
                        char new_msg[30];
                        sprintf(new_msg,"stdmsg/%s.txt",student_id);
                        char full_msg[300];
                        printf("\n\t\t[+] Message: ");
                        gets(full_msg);
                        FILE *nmsg;
                        nmsg=fopen(new_msg,"w");
                        fwrite(full_msg,strlen(full_msg),1,nmsg);
                        fclose(nmsg);
                    }
                    else if(std_ch==2){
                        update_info("studentspass/",student_id,"\t\t\t[+] Choose new password: ");
                    }
                    else{
                        printf("\n\n\t\t\t[*] You choose Wrong option...");
                    }
                }
                else{
                    printf("\n\t\t[-] Wrong password...!");
                    printf("\n\t\t[-] OR Admin Block your account.");
                    printf("\n\t\t[-] Contact with register admin.");
                }

            }
            else{
                    printf("\t\t[-] This id not exist...!");
            }
        }else{
        printf("\n\t\t[-] Input [1] or [2] not others number.\n\n"); /* First input condition*/
        }


        printf("\n\n\t\tRestart program(y/n): ");
        scanf(" %c",&restartchar);
        if(restartchar=='y')
            restart=1;
        else if(restartchar=='n')
            restart=0;
        else{
            break;
        }

    }
    return 0;
}








/*
+------------------------------------------+
|                                          |
|       All function reserved here..!      |
|                                          |
+------------------------------------------+
*/

/*-----------------------------------------------------------------------
register file function
param1:location; param2:file name; param3:file type[Name:];
*/
void file_register(char loc_register[40], char file_register[40],char register_type[40])
{
    char out_register[40];
    sprintf(out_register,"%s%s.txt",loc_register,file_register);
    if(access(out_register, F_OK)==0){
        printf("\t\t[-] Already registered!\n\n");
    }else{
        char input_register[300];
        printf("%s",register_type);
        gets(input_register);
        FILE *fp;
        fp=fopen(out_register,"w");
        fwrite(input_register,strlen(input_register),1,fp);
        fclose(fp);
    }
}

/*
--------------------------------------------------------
search file function
param1: location; param2: filename; param3: type[Name:];
*/
void search_file(char loc_search[40], char file_search[40],char type_search[40])
{
    char out_search[40];
    sprintf(out_search,"%s%s.txt",loc_search,file_search);

    if(access(out_search,F_OK)==0){
        FILE *fq;
        fq=fopen(out_search,"r");
        char out_search_str[300];
        fgets(out_search_str,300,fq);
        fclose(fq);
        printf("%s%s",type_search,out_search_str);
    }else{
        printf("\n\t\t[-] File not registered yet..!");
    }

}

/*
---------------------------------
update function
param1: location; param2: filename; param3: type[Name:];
*/
void update_info(char loc_file[40], char update_file[40],char update_type[40])
{
    char out_update[40];
    sprintf(out_update,"%s%s.txt",loc_file,update_file);

    if(access(out_update,F_OK)==0){
        char update_input[300];
        printf("%s",update_type);
        gets(update_input);
        FILE *fu;
        fu=fopen(out_update,"w");
        fwrite(update_input,strlen(update_input),1,fu);
        fclose(fu);
    }
    else{
        printf("\n\t\t[-] File not exist which you want to update.");
    }
}

/*
delete function
param1: location file; parram2: filename; param3: type[name];
*/
void delete_file(char del_loc[30],char del_file[40],char del_type[40])
{
    char out_del[50];
    sprintf(out_del,"%s%s.txt",del_loc,del_file);
    int status_del;
    status_del=remove(out_del);

    if(status_del==0){
        printf("\n\t\t[*] Delete %s successfully.",del_type);
    }
    else{
        printf("\n\n\t\t[-] Can't delete file or file not exist.\n");
    }
}
