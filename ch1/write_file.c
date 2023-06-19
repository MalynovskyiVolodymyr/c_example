#include <stdio.h>
/* * *
 * The line fseek (fp, 10, SEEK_CUR) moves the file
 * pointer 10 bytes ahead of the current position, 
 * so this program will print all but the first 
 * ten characters in the file. 
 * The first argument to fseek is the file pointer; 
 * the second is the offset by which the pointer is to move.
 * This can be positive or negative; so fseek (fp, -5, SEEK_CUR)
 * moves the pointer 5 bytes back from the current position.
 * The third argument to fseek allows you to choose a position 
 * relative to the start of the file ( SEEK_SET ) or the end of the file
 * ( SEEK_END ) rather than the current position ( SEEK_CUR ).
 * So fseek (fp, 12, SEEK_SET) positions the 
 * pointer 12 bytes ahead of the start of the file,
 * while fseek (fp, -17, SEEK_END) positions it 17 bytes
 * back from the end of the file. *
 * */
void write_fseek(void){
    FILE *fp;
    int value;

    fp = fopen("./output.txt", "rb");

    if(fp){
        fseek(fp, 10, SEEK_CUR);// skip 10 bytes

        while(1){
            value = fgetc(fp);
            if(value == EOF) break;
            else printf("%c", value);
        }
        fclose(fp);
    }
}


/* * *
 * You can open a file for simultaneous reading and writing
 * with the same pointer. Set the file
 * access mode to "rb+" to read an existing file and to overwrite it;
 * set it to "wb+" to create a new file and be able to read 
 * back what you’ve written to it;
 * set it to "ab+" to open a file to both 
 * append at the end and read from it.
 * */
void write_bytes(void){
    FILE *fp;
    int value;

    fp = fopen("./output.txt", "wb");

    if(fp){
        for(value = 48; value < 58; value++){
            fputc(value, fp);
        }
        fclose(fp);
    }
    
}

void write_text(void){
    FILE *fp;

    fp = fopen("./output.txt", "wb");

    if(fp){
        fprintf(fp, "This is some text.\n");
        fclose(fp);
    }
}

void main(void){
    write_text();
}
