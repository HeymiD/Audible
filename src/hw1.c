#include <stdlib.h>

#include "debug.h"
#include "hw1.h"


#ifdef _STRING_H
#error "Do not #include <string.h>. You will get a ZERO."
#endif

#ifdef _STRINGS_H
#error "Do not #include <strings.h>. You will get a ZERO."
#endif

#ifdef _CTYPE_H
#error "Do not #include <ctype.h>. You will get a ZERO."
#endif

/*
 * You may modify this file and/or move the functions contained here
 * to other source files (except for main.c) as you wish.
 *
 * IMPORTANT: You MAY NOT use any array brackets (i.e. [ and ]) and
 * you MAY NOT declare any arrays or allocate any storage with malloc().
 * The purpose of this restriction is to force you to use pointers.
 * Variables to hold the content of three frames of audio data and
 * two annotation fields have been pre-declared for you in const.h.
 * You must use those variables, rather than declaring your own.
 * IF YOU VIOLATE THIS RESTRICTION, YOU WILL GET A ZERO!
 *
 * IMPORTANT: You MAY NOT use floating point arithmetic or declare
 * any "float" or "double" variables.  IF YOU VIOLATE THIS RESTRICTION,
 * YOU WILL GET A ZERO!
 */

/**
 * @brief Validates command line arguments passed to the program.
 * @details This function will validate all the arguments passed to the
 * program, returning 1 if validation succeeds and 0 if validation fails.
 * Upon successful return, the selected program options will be set in the
 * global variables "global_options", where they will be accessible
 * elsewhere in the program.
 *
 * @param argc The number of arguments passed to the program from the CLI.
 * @param argv The argument strings passed to the program from the CLI.
 * @return 1 if validation succeeds and 0 if validation fails.
 * Refer to the homework document for the effects of this function on
 * global variables.
 * @modifies global variable "global_options" to contain a bitmap representing
 * the selected options.
 */
int hex_checker_helper(char c){
    if(c >= '0' && c<= '9'){
        return 1;
    }
    if(c>='A'&& c<='F'){
        return 1;
    }
    if(c>='a'&& c<='f'){
        return 1;
    }
    return 0;
}

int hex_checker(char *pointer){
    char c = *pointer;
    int hex_true=0;
    int i=0;
    while(c!='\0'){
        if(hex_checker_helper(c)){
            hex_true=1;
            i=i+1;
            c=*(pointer+i);
        }
        else return 0;
    }
    return hex_true;
}

int size(char *pointer){
    int size=0;
    char c = *pointer;
    while(c!='\0'){
        size=size+1;
        c=*(pointer+size);
    }
    return size;
}

unsigned long int_to_hex(int size,char *pointer){

    unsigned long number = 0x0000000000000000;

    char c =*(pointer);
    int digit;
    int i=0;

    if(size==4){digit=1000;}
    if(size==3){digit=100;}
    if(size==2){digit=10;}
    if(size==1){digit=1;}

    while(c!='\0'){
        number = number + digit*(c-'0');
        digit=digit/10;
        i++;
        c=*(pointer+i);
    }
    return number;
}

unsigned long shifter_f(unsigned long n){
    n=n-0x0000000000000001;
    return n<<48;
}

unsigned long char_hex(int s,char *pointer){

    char c=*pointer;


    unsigned long number =0x0000000000000000;
    //unsigned long temp_n=0x0000000000000000;
    unsigned long temp;


    for(int i=0;i<s;i++){
        c=*(pointer+i);
        if(c>='A'&&c<='F'){
            temp=c-55;
        }
        if(c>='a'&&c<='f'){
            temp=c-87;
        }
        if(c>='0'&&c<='9'){
            temp=c-48;
        }
       //printf("0x%lx\n", temp);
        int shift_amn = 4*(s-i-1);
        temp=temp<<shift_amn;
        number=number | temp;

    }
    //printf("0x%lx\n", number);

    return number;
}


int check_smaller_1024(int size, char *pointer){
    char c = *pointer;
    if(size<4){
        int incrementer = 0;
        int int_true=0;
        while(c!='\0'){
            if(c>='0'&& c<='9'){
                int_true=1;
                incrementer=incrementer+1;
                c=*(pointer+incrementer);
            }
            else return 0;
        }
        return int_true;
    }
    if(size==4){
        if(c<='1'){
            c=*(pointer+1);
            if(c=='0'){
                c=*(pointer+2);
                if(c<'3' && c>='0'){
                    c=*(pointer+3);
                    if(c<'5'&&c>='0'){
                        return 1;
                    }
                    return 0;
                }
                return 0;
            }
            return 0;
        }
    }
    return 0;
}

int check_h_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='h'){
            return 1;
        }
        return 0;
    }
    return 0;
}
int check_u_or_d_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='u'||c=='d'){
            return 1;
        }
        return 0;
    }
    return 0;
}
int check_c_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='c'){
            return 1;
        }
        return 0;
    }
    return 0;
}
int check_p_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='p'){
            return 1;
        }
        return 0;
    }
    return 0;
}
int check_f_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='f'){
            return 1;
        }
        return 0;
    }
    return 0;
}

int check_k_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='k'){
            return 1;
        }
        return 0;
    }
    return 0;
}

int check_u_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='u'){
            return 1;
        }
        return 0;
    }
    return 0;
}
int check_d_flag(char *pointer){
    char c = *pointer;
    if(c=='-'){
        c=*(pointer+1);
        if(c=='d'){
            return 1;
        }
        return 0;
    }
    return 0;
}




void modify_go_h(){
    unsigned long go=global_options;
    unsigned long one=0x8000000000000000;
    global_options = global_options | one;
}

void modify_go_u(){
    unsigned long go=global_options;
    unsigned long one=0x4000000000000000;
    global_options = global_options | one;
}

void modify_go_d(){
    unsigned long go=global_options;
    unsigned long one=0x2000000000000000;
    global_options = global_options | one;
}

void modify_go_c(){
    unsigned long go=global_options;
    unsigned long one=0x1000000000000000;
    global_options = global_options | one;
}

void modify_go_p(){
    unsigned long go=global_options;
    unsigned long one=0x0800000000000000;
    global_options = global_options | one;
}



int validargs(int argc, char **argv)
{

    if(argc>1&&argc<6){

        char *pointer=*(argv+1);
        if(check_h_flag(pointer)){
            modify_go_h();
            //printf("0x%lx\n", global_options);
            return 1;
        }

        if(check_u_or_d_flag(pointer)){
            if(check_u_flag(pointer)){
                modify_go_u();
                //printf("0x%lx\n", global_options);
            }
            else {
                modify_go_d();
            //printf("0x%lx\n", global_options);
        }

            if(argc==2){return 1;}
            if(argc==3){
                pointer =*(argv+2);
                if(check_p_flag(pointer)){
                    modify_go_p();
                    //printf("0x%lx\n", global_options);
                    return 1;}
                return 0;
            }
            if(argc==4){
                pointer =*(argv+2);
                if(check_f_flag(pointer)){
                    pointer=*(argv+3);
                    int s=size(pointer);
                    if(check_smaller_1024(s,pointer)){
                        unsigned long n =int_to_hex(s,pointer);
                        n=shifter_f(n);
                        global_options=global_options|n;
                        //printf("0x%lx\n", global_options);
                        return 1;}
                    return 0;
                }
                return 0;
            }
            if(argc==5){
                pointer=*(argv+2);
                if(check_p_flag(pointer)){
                    modify_go_p();
                    //printf("0x%lx\n", global_options);
                    pointer=*(argv+3);
                    if(check_f_flag(pointer)){
                        pointer=*(argv+4);
                        int s=size(pointer);
                        if(check_smaller_1024(s,pointer)){
                            unsigned long n =int_to_hex(s,pointer);
                        n=shifter_f(n);
                        global_options=global_options|n;
                        //printf("0x%lx\n", global_options);
                            return 1;}
                        return 0;
                    }
                    return 0;
                }
                if(check_f_flag(pointer)){
                    pointer=*(argv+3);
                    int s=size(pointer);
                    if(check_smaller_1024(s,pointer)){
                        unsigned long n =int_to_hex(s,pointer);
                        n=shifter_f(n);
                        global_options=global_options|n;
                        //printf("0x%lx\n", global_options);
                        pointer=*(argv+4);
                        if(check_p_flag(pointer)){
                            modify_go_p();
                            //printf("0x%lx\n", global_options);
                            return 1;}
                        return 0;
                    }
                    return 0;
                }
                return 0;
            }
            return 0;
        }

        if(check_c_flag(pointer)){
            modify_go_c();
            //printf("0x%lx\n", global_options);
            if(argc>=4){
                pointer=*(argv+2);
                if(argc==4){
                    if(check_k_flag(pointer)){
                        pointer=*(argv+3);
                        if(hex_checker(pointer)){
                            int s = size(pointer);
                            unsigned long a =char_hex(s,pointer);
                            global_options = global_options | a;
                            //printf("0x%lx\n", global_options);
                            return 1;}
                        return 0;
                    }
                    return 0;
                }
                if(argc==5){
                    if(check_p_flag(pointer)){
                        modify_go_p();
                        //printf("0x%lx\n", global_options);
                        pointer=*(argv+3);
                        if(check_k_flag(pointer)){
                            pointer=*(argv+4);
                            if(hex_checker(pointer)){
                                int s = size(pointer);
                                unsigned long a =char_hex(s,pointer);
                                global_options = global_options | a;
                                //printf("0x%lx\n", global_options);
                                return 1;}
                            return 0;
                        }
                        return 0;
                    }
                    if(check_k_flag(pointer)){
                        pointer=*(argv+3);

                        if(hex_checker(pointer)){
                            int s = size(pointer);
                            unsigned long a =char_hex(s,pointer);
                                global_options = global_options | a;
                                //printf("0x%lx\n", global_options);
                            pointer=*(argv+4);
                            if(check_p_flag(pointer)){
                                modify_go_p();
                                //printf("0x%lx\n", global_options);
                                return 1;}
                            return 0;
                        }
                        return 0;
                    }
                    return 0;
                }
                return 0;
            }
            return 0;
        }
        return 0;
}
    return 0;
}

/**
 * @brief  Recodes a Sun audio (.au) format audio stream, reading the stream
 * from standard input and writing the recoded stream to standard output.
 * @details  This function reads a sequence of bytes from the standard
 * input and interprets it as digital audio according to the Sun audio
 * (.au) format.  A selected transformation (determined by the global variable
 * "global_options") is applied to the audio stream and the transformed stream
 * is written to the standard output, again according to Sun audio format.
 *
 * @param  argv  Command-line arguments, for constructing modified annotation.
 * @return 1 if the recoding completed successfully, 0 otherwise.
 */



int read_header(AUDIO_HEADER *hp){

    unsigned long magic_number = getchar();
    magic_number=magic_number<<24;
    for(int i=0;i<3;i++){
        unsigned long mc = getchar();
        magic_number = magic_number | (mc<<8*(3-i-1));
    }

    if(AUDIO_MAGIC!=magic_number){
        return 0;
    }
    (*hp).magic_number = magic_number;

    //long unsigned m =(*hp).magic_number;
    //printf("Magic Number :0x%lx\n", m);

    unsigned long data_offset = getchar();
    data_offset=data_offset<<24;
    for(int i=0;i<3;i++){
        unsigned long d_o = getchar();
        data_offset = data_offset | (d_o<<8*(3-i-1));
    }

    if(data_offset % 8 != 0){return 0;}

    (*hp).data_offset = data_offset;

    //long unsigned da =(*hp).data_offset;
    //printf("Data Offset :0x%lx\n", da);

    unsigned long data_size = getchar();
    data_size=data_size<<24;
    for(int i=0;i<3;i++){
        unsigned long ds = getchar();
        data_size = data_size | (ds<<8*(3-i-1));
    }

    (*hp).data_size = data_size;

    //long unsigned dsize =(*hp).data_size;
    //printf("Data size: 0x%lx\n", dsize);

    unsigned long encoding = getchar();
    encoding=encoding<<24;
    for(int i=0;i<3;i++){
        unsigned long en = getchar();
        encoding = encoding | (en<<8*(3-i-1));
    }

    if(encoding!=0x2 && encoding!=0x3 && encoding!=0x4 && encoding!=0x5 ){return 0;}
    (*hp).encoding=encoding;

    //long unsigned enc =(*hp).encoding;
    //printf("Encoding: 0x%lx\n", enc);

    unsigned long sample_rate = getchar();
    sample_rate=sample_rate<<24;
    for(int i=0;i<3;i++){
        unsigned long sr = getchar();
        sample_rate = sample_rate | (sr<<8*(3-i-1));
    }

    (*hp).sample_rate=sample_rate;

    //long unsigned sample_r =(*hp).sample_rate;
    //printf("Sample Rate: 0x%lx\n", sample_r);

    unsigned long number_channels = getchar();
    number_channels=number_channels<<24;
    for(int i=0;i<3;i++){
        unsigned long nc = getchar();
        number_channels = number_channels | (nc<<8*(3-i-1));
    }

    if(number_channels!=0x1 && number_channels!=0x2 ){return 0;}
    (*hp).channels=number_channels;

    //long unsigned numch =(*hp).channels;
    //printf("Channels: 0x%lx\n", numch);


    return 1;



}

int write_header(AUDIO_HEADER *hp){

    for(int i=0;i<4;i++){
        putchar((*hp).magic_number>>(8*(4-i-1)));}


    for(int i=0;i<4;i++){
        putchar((*hp).data_offset>>(8*(4-i-1)));}


    for(int i=0;i<4;i++){
        putchar((*hp).data_size>>(8*(4-i-1)));}


    for(int i=0;i<4;i++){
        putchar((*hp).encoding>>(8*(4-i-1)));}


    for(int i=0;i<4;i++){
        putchar((*hp).sample_rate>>(8*(4-i-1)));}


    for(int i=0;i<4;i++){
        putchar((*hp).channels>>(8*(4-i-1)));}


    return 1;
}

int read_annotation(char *ap, unsigned int size){

    for(int i=0;i<size;i++){
        *(ap+i)=getchar();
        if(i==size-1){
            if(*(ap+i)!='\0'){return 0;}
        }
    }


    return 1;
}

int write_annotation(char *ap, unsigned int size){

    for(int i=0;i<size;i++){
        putchar(*(ap+i));
    }

    return 1;
}

int read_frame(int *fp, int channels, int bytes_per_sample){



    for(int i=0; i<channels;i++){

        signed int int_value=0;
        int neg = 0;

        for(int j=0; j<bytes_per_sample;j++){
            int character = getchar();
            char ch = character;

            if(character==EOF){return 0;}

           if(j==0){
                if((ch & 0x80)==0x80){
                    neg=1;
                }
            }


            signed int val1=(char)character<<(8*(bytes_per_sample-j-1));
            int_value=int_value | val1;

        }

        if(neg==1){
            if(bytes_per_sample==1){
                int_value=int_value | 0xffffff00;
            }
            if(bytes_per_sample==2){
                int_value=int_value | 0xffff0000;
            }
            if(bytes_per_sample==3){
                int_value=int_value | 0xff000000;
            }
        }

        *(fp+i)=int_value;

    }



    return 1;
}

int write_frame(int *fp, int channels, int bytes_per_sample){

    for(int i=0; i<channels;i++){
        signed int val=*(fp+i);
        for(int j=0; j<bytes_per_sample;j++){
            signed int val1 = val>>(8*(bytes_per_sample-j-1));
            signed int val2 = val1 & 0xff;
            if(putchar(val2)==EOF){return 0;}

        }
    }
    return 1;
}

void swap_frame(int *fp1, int *fp2, int channels){
    for(int i=0;i<channels;i++){
        signed int value = *(fp2+i);
        *(fp1+i)=value;
    }
}

int read_out_frame(int *fp, int *value,int channels, int bytes_per_sample){




    //printf("%d\n", random_number);

    for(int i =0; i<channels;i++){


        signed int random_number = myrand32();
        signed int sample_value = *(value+i);
        signed int encyrpted_val= sample_value ^ random_number;

        *(fp+i)=encyrpted_val;



    }


    return 1;
}

int read_factored_frame(int *fp, int *prev, int *input, int channels, int factor, int bytes_per_sample){





    for(int j=1;j<factor;j++){

        for(int i=0;i<channels;i++){
            signed int prev_val=*(prev+i);
            signed int input_val=*(input+i);
            signed int difference = input_val-prev_val;

        signed int new_val= ((difference*j)/factor);

        *(fp+i)=prev_val+new_val;

        }

        if(write_frame(fp,channels,bytes_per_sample)==0){return 0;}


    }



    return 1;
}

int recode(char **argv) {

    AUDIO_HEADER audio_header;
    AUDIO_HEADER *header_pointer=&audio_header;


    read_header(header_pointer);



    read_annotation(input_annotation,audio_header.data_offset-24);



    unsigned long first_byte=(global_options&0xf000000000000000)>>60;
    unsigned long p_value = (global_options&0x0800000000000000)>>59;
    unsigned int factor_value = (global_options&0x03ff000000000000)>>48;
    factor_value=factor_value+1;
    unsigned long key_value = global_options&0xffffffff;





    int s=0;
    while(*(argv+s)!=NULL){
        s=s+1;
    }

    unsigned int i=0;


    for(int counter=0;counter<s;counter++){
        char *pointer = *(argv+counter);
        char c =*pointer;
        int a=0;
        while(c!='\0'){
            *(output_annotation+i)=c;
            i++;
            a++;
            c=*(pointer+a);
        }
        if(counter<s-1){
            *(output_annotation+i)=' ';
        i++;
        }
    }

    *(output_annotation+i)='\n';
    i++;




    if(first_byte==0x4){

    unsigned int new_data_size = 0;

    for(int cn=0;cn<audio_header.data_size/(audio_header.channels*(audio_header.encoding-1));cn++){
        if(cn%factor_value==0){
            new_data_size = new_data_size + audio_header.channels*(audio_header.encoding-1);}
    }
    int old_data_size = audio_header.data_size;
    audio_header.data_size=new_data_size;
    int old_data_offset =audio_header.data_offset;
    if(p_value==0){audio_header.data_offset = audio_header.data_offset+i+8-(i%8);}

    write_header(header_pointer);


    if(p_value==0x0){
        write_annotation(output_annotation,i);
        write_annotation(input_annotation,(old_data_offset-24)+8-(i%8));



    }
    if(p_value==0x1){
        write_annotation(input_annotation,audio_header.data_offset-24);
    }

        char *frame_pointer;

        frame_pointer = input_frame;


        for(int in=0;in<old_data_size/(audio_header.channels*(audio_header.encoding-1));in++){

        if(read_frame((int*)frame_pointer,audio_header.channels,audio_header.encoding-1)==0){
            return 0;
        }

        if(in%factor_value==0){
            if(write_frame((int*)frame_pointer,audio_header.channels,audio_header.encoding-1)==0){return 0;}
        }
    }

    return 1;
    }

    if(first_byte==2){

    int old_data_size= audio_header.data_size;
    int new_data_size = (audio_header.channels*(audio_header.encoding-1))
    *((old_data_size/((audio_header.channels)*(audio_header.encoding-1)))+
    (factor_value-1)*((old_data_size/((audio_header.channels)*(audio_header.encoding-1)))-1));//old_data_size+((old_data_size-1)*(factor_value-1));

    audio_header.data_size=new_data_size;
    int old_data_offset =audio_header.data_offset;
    if(p_value==0x0){audio_header.data_offset = audio_header.data_offset+i+8-(i%8);}

    write_header(header_pointer);


    if(p_value==0x0){
        write_annotation(output_annotation,i);
        write_annotation(input_annotation,(old_data_offset-24)+8-(i%8));



    }
    if(p_value==0x1){
        write_annotation(input_annotation,audio_header.data_offset-24);
    }

        char *frame_pointer;

        frame_pointer = input_frame;

        char *prev_frame_pointer=previous_frame;



        char *output_fr = output_frame;






        if(read_frame((int*)prev_frame_pointer,audio_header.channels,audio_header.encoding-1)==0){return 0;}

        for(int k=1;k<old_data_size/(audio_header.channels*(audio_header.encoding-1));k++){

            if(read_frame((int*)frame_pointer,audio_header.channels,audio_header.encoding-1)==0){return 0;}

            if(write_frame((int*)prev_frame_pointer,audio_header.channels,audio_header.encoding-1)==0){return 0;}
            if(read_factored_frame((int*)output_fr,(int*)prev_frame_pointer, (int*)frame_pointer, audio_header.channels,
                factor_value, audio_header.encoding-1)==0){return 0;}

            swap_frame((int*)prev_frame_pointer,(int*)frame_pointer,audio_header.channels);

    }

    if(write_frame((int*)frame_pointer,audio_header.channels,audio_header.encoding-1)==0){return 0;}
    return 1;
}

    if(first_byte==0x1){




        int old_data_offset =audio_header.data_offset;
    if(p_value==0){audio_header.data_offset = audio_header.data_offset+i+8-(i%8);}

    write_header(header_pointer);


    if(p_value==0x0){
        write_annotation(output_annotation,i);
        write_annotation(input_annotation,(old_data_offset-24)+8-(i%8));



    }
    if(p_value==0x1){
        write_annotation(input_annotation,audio_header.data_offset-24);
    }

        mysrand(key_value);

        char *frame_pointer;

        frame_pointer = input_frame;

        char *output_fr=output_frame;




        for(int in=0;in<audio_header.data_size/(audio_header.channels*(audio_header.encoding-1));in++){
            if(read_frame((int*)frame_pointer,audio_header.channels,audio_header.encoding-1)==0){return 0;}
        read_out_frame((int*)output_fr,(int*)frame_pointer,audio_header.channels,audio_header.encoding-1);
        if(write_frame((int*)output_fr,audio_header.channels,audio_header.encoding-1)==0){return 0;}
        }

        return 1;



    }


    return 0;
}







