#ifndef BUTTON_H
#define BUTTON_H
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *button;
    int width;
    int height;
    int grid_column;
    int grid_row;
    int grid_width;
    int grid_height;
} button_t;

/*
* Defined OPEN_USB_BUTTON and set this even, when click to Open USB button
*/
button_t *open_usb_button_new(GtkWidget *windows);
void open_usb_button_clicked(GtkButton *open_usb_button, gpointer data);
static void on_open_usb_dialog(GtkDialog *dialog, int response_id, gpointer data);

#endif