#include <stdio.h>

int sum_and_diff(int a, int b, int *res){
	int sum;
	sum = a + b;
	*res = a - b;
	return sum;
}

void void_pointer(void){
	int intval = 227887;
	void *vptr = &intval;
	
	printf("The value at vptr as an int is %d\n", *((int*) vptr));
	printf("The value at vptr as a char is %d\n", *((char*) vptr));
}

void simple_pointer(void){
	int a;
	int *ptr_to_a;
	
	ptr_to_a = &a;
	
	a = 5;
	printf("The value of a is %d\n", a);

	*ptr_to_a = 6;
	printf("The value of a is %d\n", a);
	printf("The value of ptr_to_a is %d\n", ptr_to_a);
	printf("It stores the value %d\n", *ptr_to_a);
	printf("The address of a is %d\n", &a);
	
}

void math_example(void){
	float a;
	float b = 3.641;
	float c;

	a = 2.897;
	c = a + b;
	printf("The sum of adding %f and %f is %.3f\n", a, b, c);
}

void old_main (void){
	printf("Hello repeating C\n");
	//math_example();
	//simple_pointer();
	//void_pointer();
	int b = 2, diff;
	
	printf("The sum of 5 and %d is %d\n", b, sum_and_diff(5, b, &diff));
	printf("The difference of 5 and %d is %d\n", b, diff);
}

///////////////////////////////////////////////////////////////////////////

void arrays(void){
	int a[10];
	int count;

	for(count = 0; count < 10; count++){
		a[count] = count * 10 + count;
	}
	printf("The first and second elements of a are %d and %d\n", a[0], a[1]);
	printf("Or, as pointers, %d and %d\n", *a, *(a+1));
}

void simple_strings(void){
	char str1[10] = "first";
	char str2[10] = "second";
	char str3[20];

	char *src, *dst;
	src = str1;
	dst = str3;

	while(*src != 0){
		*dst = *src;
		src++;
		dst++;
	}

	src = str2;
	while(*src != 0){
		*dst = *src;
		src++;
		dst++;
	}

	*dst = 0;
	printf("%s + %s = %s\n", str1,  str2, str3);

}

void string_sprintf(void){
	int val = 12;
	char string[50];

	sprintf(string, "The value of val is %d\n", val);
	printf("%s",string);
}


#include <string.h>

void string_1(){
	char str1[10] = "first";
	char str2[10] = "second";
	char str3[20];
	
	// strcpy -- copy string 
	strcpy(str3, str1);
	// strcat -- concatenate string
	strcat(str3, str2);
	
	printf("%s + %s = %s\n", str1, str2, str3);
}

void comparing_strings(void){
	char str1[10] = "first";
	char str2[10] = "fire";
	char *ptr1 = str1, *ptr2 = str2;

	while(*ptr1 != 0 && *ptr2 != 0){
		if(*ptr1 != *ptr2){
			break;
		}
		ptr1++;
		ptr2++;
	}

	if(*ptr1 == 0 && *ptr2 == 0){	
		printf("The two strings are identical\n");
	}else{
		printf("The two strings are different\n");
	}

}

void comparing_strings2(void){
	char str1[10] = "first";
	char str2[10] = "first";
	
	// strcmp -- comparing strings
	if(strcmp(str1, str2) == 0){
		printf("The two strings are identical\n");
	}else{
		printf("The tow strings are different\n");
	}
}

void read_string(){
	int val;
	char string[10] = "250";
	sscanf(string, "%d", &val);
	printf("The value in the string is %d\n", val);
}

void read_string1(){
	int val;
	char result[10];
	char string[25] = "The first number is 1";

	if(sscanf(string, "The %s number is %d", result, &val) == 2){
		printf("String : %s VALUE : %d LENGTH : %d\n", 
						result, val, strlen(result));
	}else{
		printf("Culd't read all values\n");
	}
}

void read_input(void){
	char input[256];
	int age;
	
	printf("What is your name?\n");
	scanf("%s", input);

	printf("Hello, %s. How old are you?\n", input);
	scanf("%d", &age);

	printf("Well, %s, you look young for %d...\n", input, age);
}

void read_input1(void){
	char input[256], name[256];
	int age;

	printf("What is your name, user?\n");
	fgets(input, 256, stdin);
	sscanf(input, "%s", name);

	printf("Hello, %s. How old are you?\n", name);

	while(1){
		fgets(input, 256, stdin);
		// sscanf returns number of correctly readed values 
		if(sscanf(input, "%d", &age) == 1){	
			break;
		}
		printf("I don't recognise that as an age - try again!\n");
	}
	
	printf("Well, %s, you look young for %d...\n", name, age);
}

void old_main1(void){
	//arrays();
	//simple_strings();
	//string_sprintf();
	//string_1();
	//comparing_strings();
	//comparing_strings2();
	//read_string1();
	read_input1();
}

void calc(int argc, char *argv[]){
	int arg1, arg2;
	
	if(argc == 4){
		sscanf(argv[1], "%d", &arg1);
		sscanf(argv[3], "%d", &arg2);
		if(*argv[2] == '+') printf("%d\n", arg1 + arg2);
		if(*argv[2] == '-') printf("%d\n", arg1 - arg2);
		if(*argv[2] == '*') printf("%d\n", arg1 * arg2);
		if(*argv[2] == '/') printf("%d\n", arg1 / arg2);
	}
}

int old_main2(int argc, char *argv[]){
	int param = 0;
	while(param < argc){
		printf("Parameter %d is %s\n", param, argv[param]);
		param++;
	}
	if(argc == 5 && (strcmp(argv[4], "calc") == 0)){
		calc(4, argv);
	}
	return 0;
}


void files_read(void){
	FILE *fp;
	int value;
	
	fp = fopen("./input.txt", "rb");

	if(fp){
		while(1){
			value = fgetc(fp);
			if(value == EOF) break;
			else printf("%c", value);
		}
		fclose(fp);
	}
}

void files_write(void){
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

void files_wformatted(void){
	FILE *fp;
	
	fp = fopen("./output.txt", "wb");
	if(fp){
		fprintf(fp, "This is some text.\n");
		fclose(fp);
	}
}

void files_read_from_position(void){
	FILE *fp;
	int value;

	fp = fopen("./input.txt", "rb");

	if(fp){
		fseek(fp, 10, SEEK_CUR);
		while(1){
			value = fgetc(fp);
			if(value == EOF) break;
			else printf("%c", value);
		}
		fclose(fp);
	}
}

void old_main3(void){
	//files_read();
	//files_write();
	//files_wformatted();
	files_read_from_position();
}

/////////////////////////////////////////////////////////////////////

// type enum has default values like 0, 1, 2, 3 ... if not defined
typedef enum{
	false,
	true
} BOOLEAN;

void test_custom_enum(void){
	BOOLEAN b_var;
	
	b_var = true;
	
	if(b_var == true){
		printf("TRUE\n");
	}else{
		printf("FALSE\n");
	}
}


typedef struct{
	int inval1;	
	int inval2;
	int outval;
} MY_DATA;

void add(MY_DATA *d){
	d->outval = d->inval1 + d->inval2;
}

void test_struct_add(void){
	MY_DATA data;

	data.inval1 = 5;
	data.inval2 = 7;
	add(&data);

	printf("The sum of %d and %d is %d\n", data.inval1, data.inval2, data.outval);
}

void old_main4(void){
	test_custom_enum();
	test_struct_add();
}
////////////////////////////////////////////////////////////////////////////////////////////
#include <gtk/gtk.h>

int old_main5(int args, char *argv[]){
	gtk_init(&args, &argv);
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(win);
	gtk_main();
	return 0;
}

///////////
void old_main6(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label("Close window");
	gtk_container_add(GTK_CONTAINER(win), btn);
	gtk_widget_show_all(win);
	gtk_main();
}
///////////

int count = 0;

void end_program(GtkWidget *wid, gpointer ptr){
	gtk_main_quit();
}

void count_button(GtkWidget *wid, gpointer ptr){
	char buffer[30];
	count++;
	sprintf(buffer, "Button pressed %d times", count);
	gtk_label_set_text(GTK_LABEL(ptr), buffer);
}


void old_main7(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label("Close window");

	g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
	g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

	GtkWidget *lbl = gtk_label_new("My label");
	GtkWidget *box = gtk_vbox_new(FALSE, 5);
	GtkWidget *btn2 = gtk_button_new_with_label("Count button");
	g_signal_connect(btn2, "clicked", G_CALLBACK(count_button), lbl);

	gtk_box_pack_start(GTK_BOX(box), btn2, TRUE, TRUE, 0);	
	gtk_box_pack_start(GTK_BOX(box), lbl, FALSE, FALSE, 10);
	gtk_box_pack_start(GTK_BOX(box), btn, FALSE, FALSE, 0);

	gtk_container_add(GTK_CONTAINER(win), box);

	gtk_widget_show_all(win);
	gtk_main();
}

void old_main8(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label("Close window");
	
	g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
	g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

	GtkWidget *lbl = gtk_label_new("My label");
	GtkWidget *btn2 = gtk_button_new_with_label("Count button");
	
	g_signal_connect(btn2, "clicked", G_CALLBACK(count_button), lbl);

	GtkWidget *tbl = gtk_table_new(2, 2, TRUE);
	gtk_table_attach_defaults(GTK_TABLE(tbl), lbl, 0, 1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(tbl), btn2, 1, 2, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 2, 1, 2);
	gtk_container_add(GTK_CONTAINER(win), tbl);
	gtk_widget_show_all(win);
	gtk_main();
}


GtkWidget *txt;
GtkWidget *txt1;

void copy_text(GtkWidget *wid, gpointer ptr){
	const char *input = gtk_entry_get_text(GTK_ENTRY(txt));
	gtk_label_set_text(GTK_LABEL(ptr), input);
}

void check_toggle(GtkWidget *wid, gpointer ptr){
	printf("The state of the button is %d\n", gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wid)));
}

void check_changed(GtkWidget *wid, gpointer ptr){	
	int sel = gtk_combo_box_get_active(GTK_COMBO_BOX(wid));
	char *selected = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(wid));
	printf("The value of the combo is %d %s\n", sel, selected);
}

void old_main9(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label("Close window");
	
	g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
	g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
	
	GtkWidget *lbl = gtk_label_new("My label");
	GtkWidget *btn2 = gtk_button_new_with_label("Copy button");
	
	g_signal_connect(btn2, "clicked", G_CALLBACK(copy_text), lbl);
	
	txt = gtk_entry_new();
	GtkObject *adj = gtk_adjustment_new(0, -10, 10, 1, 0, 0);
	txt1 = gtk_spin_button_new(GTK_ADJUSTMENT(adj), 0, 0);
	
	GtkWidget *tab = gtk_table_new(2, 2, TRUE);
	GtkWidget *chk = gtk_check_button_new_with_label("My check");
	// set active
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(chk), TRUE);
	// get state
	int state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chk));
	g_signal_connect(chk, "toggled", G_CALLBACK(check_toggle), NULL);
	
	GtkWidget *rad1 = gtk_radio_button_new_with_label(NULL, "Button 1");
	GSList *group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(rad1));
	GtkWidget *rad2 = gtk_radio_button_new_with_label(group, "Button 2");	

	
	GtkWidget *comb = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 1");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 2");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 3");
	gtk_combo_box_set_active(GTK_COMBO_BOX(comb), 0);

	g_signal_connect(comb, "changed", G_CALLBACK(check_changed), NULL);
	///////////////
	
	int pos = 0;
	GtkListStore *ls = gtk_list_store_new(1, G_TYPE_STRING);
	gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 1", -1);
	gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 2", -1);
	gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 3", -1);
	
	GtkWidget *comb1 = gtk_combo_box_new_with_model(GTK_TREE_MODEL(ls));
	GtkCellRenderer *rend = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(comb1), rend, FALSE);
	gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(comb1), rend, "text", 0);
	
	gtk_table_attach_defaults(GTK_TABLE(tab), lbl, 0, 1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(tab), btn2, 1, 2, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(tab), btn, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(tab), txt, 1, 2, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(tab), txt1, 1, 2, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(tab), chk, 0, 1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(tab), rad1, 0, 1, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(tab), rad2, 1, 2, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(tab), comb, 0, 1, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(tab), comb1, 1, 2, 4, 5);
	gtk_container_add(GTK_CONTAINER(win), tab);
	gtk_widget_show_all(win);
	gtk_main();
}
/////////////////
void row_selected(GtkWidget *wid, gpointer ptr){	
	GtkTreeSelection *sel;
	GtkTreeModel *model;
	GtkTreeIter iter;
	char *option;

	sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(wid));
		
	if(gtk_tree_selection_get_selected(sel, &model, &iter)){
		gtk_tree_model_get(model, &iter, 0, &option, -1);
		printf("The selected row contains the text %s\n", option);
	}
}


void old_main10(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);	
	GtkWidget *btn = gtk_button_new_with_label("Close window");
	g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
	g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

	int pos = 0;
	GtkListStore *ls = gtk_list_store_new(2, G_TYPE_STRING, GDK_TYPE_PIXBUF);
	GdkPixbuf *icon = gtk_icon_theme_load_icon(gtk_icon_theme_get_default(), "emblem-default", 32, 0, NULL);
	
	gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 1", 1, icon, -1);
	gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 2", 1, icon, -1);
	gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 3", 1, icon, -1);

	GtkWidget *tv = gtk_tree_view_new_with_model(GTK_TREE_MODEL(ls));
	
	GtkCellRenderer *prend = gtk_cell_renderer_pixbuf_new();
	GtkCellRenderer *trend = gtk_cell_renderer_text_new();
	
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv), -1, "Icon", prend, "pixbuf", 1, NULL);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv), -1, "Option", trend, "text", 0, NULL);
	///////
	g_signal_connect(tv, "cursor-changed", G_CALLBACK(row_selected), NULL);


	GtkWidget *tbl = gtk_table_new(2, 2, FALSE);
	gtk_table_attach_defaults(GTK_TABLE(tbl), tv, 0, 2, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 1, 1, 2);
	gtk_container_add(GTK_CONTAINER(win), tbl);
	gtk_widget_show_all(win);
	gtk_main();


}

/////////////menu && popup
void button_popup(GtkWidget *wid, gpointer ptr){	
	GtkWidget *f_menu = gtk_menu_new();	
	GtkWidget *quit_mi = gtk_menu_item_new_with_label("Quit");
	gtk_menu_shell_append(GTK_MENU_SHELL(f_menu), quit_mi);
	g_signal_connect(quit_mi, "activate", G_CALLBACK(end_program), NULL);
	gtk_widget_show_all(f_menu);
	gtk_menu_popup(GTK_MENU(f_menu), NULL, NULL, NULL, NULL, 1, gtk_get_current_event_time());
}

void open_dialog(GtkWidget *wid, gpointer ptr){
	GtkWidget *dlg = gtk_dialog_new_with_buttons("my dialog",
			GTK_WINDOW(ptr),
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			"Cansel", 0, "Ok", 1, NULL);

	GtkWidget *lbl = gtk_label_new("A question for the user");
	gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(GTK_DIALOG(dlg))), lbl);
	
	gtk_widget_show(lbl);
	
	int result = gtk_dialog_run(GTK_DIALOG(dlg));
	gtk_widget_destroy(dlg);
	printf("Rerturn code = %d\n", result);
}


void old_main11(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label("Close window");
	GtkWidget *btn1 = gtk_button_new_with_label("Show dialog");
	
	g_signal_connect(btn, "clicked", G_CALLBACK(button_popup), NULL);
	g_signal_connect(btn1, "clicked", G_CALLBACK(open_dialog), NULL);
	g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
	
	GtkWidget *mbar = gtk_menu_bar_new();
	GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), mbar, TRUE, TRUE, 0);
	gtk_container_add(GTK_CONTAINER(win), vbox);

	GtkWidget *file_mi = gtk_menu_item_new_with_label("File");
	gtk_menu_shell_append(GTK_MENU_SHELL(mbar), file_mi);	

	GtkWidget *f_menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_mi), f_menu);

	GtkWidget *quit_mi = gtk_menu_item_new_with_label("Quit");
	gtk_menu_shell_append(GTK_MENU_SHELL(f_menu), quit_mi);
	g_signal_connect(quit_mi, "activate", G_CALLBACK(end_program), NULL);

	gtk_box_pack_start(GTK_BOX(vbox), btn, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), btn1, TRUE, TRUE, 0);
	gtk_widget_show_all(win);
	gtk_main();
}
//////////
static void file_selected(GtkFileChooserButton *btn, gpointer ptr){
	printf("%s selected\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(btn)));	
}

static void save_file(GtkWidget *btn, gpointer ptr){
	GtkWidget *sch = gtk_file_chooser_dialog_new("Save file", GTK_WINDOW(ptr), GTK_FILE_CHOOSER_ACTION_SAVE, "Cancel", 0, "OK", 1, NULL);

	if(gtk_dialog_run(GTK_DIALOG(sch)) == 1){
		printf("%s selected\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(sch)));
	}
	gtk_widget_destroy(sch);
}

static void col_selected(GtkColorButton *btn, gpointer ptr){
	GdkColor col;
	gtk_color_button_get_color(btn, &col);
	printf("red = %d; green = %d; blue = %d\n", col.red, col.green, col.blue);
}

static void fnt_selected(GtkFontButton *btn, gpointer ptr){
	printf("font = %s\n", gtk_font_button_get_font_name(btn));
}

void main(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn = gtk_button_new_with_label("Close window");
	GtkWidget *btn1 = gtk_button_new_with_label("Save dialog");
	GtkWidget *col_btn = gtk_color_button_new();
	GtkWidget *fnt_btn = gtk_font_button_new();
	
	g_signal_connect(fnt_btn, "font-set", G_CALLBACK(fnt_selected), NULL);
	g_signal_connect(col_btn, "color-set", G_CALLBACK(col_selected), NULL);
	g_signal_connect(btn1, "clicked", G_CALLBACK(save_file), NULL);
	g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);	
	g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
	
	GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
	gtk_container_add(GTK_CONTAINER(win), vbox);

	GtkWidget *fc_btn = gtk_file_chooser_button_new("Select file", GTK_FILE_CHOOSER_ACTION_OPEN);
	g_signal_connect(fc_btn, "file-set", G_CALLBACK(file_selected), NULL);
	gtk_box_pack_start(GTK_BOX(vbox), fc_btn, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), btn, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), btn1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), col_btn, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), fnt_btn, TRUE, TRUE, 0);
	gtk_widget_show_all(win);
	gtk_main();
}









