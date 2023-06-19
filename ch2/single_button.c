#include <gtk/gtk.h>

void end_program(GtkWidget *wid, gpointer ptr){
    gtk_main_quit();
}

void main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *btn = gtk_button_new_with_label("Close window");
    // connecting an event to a button
    g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
    // coonecting event to a X in to right corner
    g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
    gtk_container_add(GTK_CONTAINER(win), btn);
    gtk_widget_show_all(win);
    gtk_main();
}
