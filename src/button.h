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

button_t *open_usb_button_new();

#endif