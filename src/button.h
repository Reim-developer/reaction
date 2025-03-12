// Define:
// Button widget.
// Button callback event.
// Dialog callback event. (Open when clicked a button widget).
#ifndef BUTTON_H
#define BUTTON_H
#include "dropbox.h"
#include <gtk/gtk.h>

// Button widget struct.
typedef struct {
    GtkWidget *button;
    dropbox_t *device_list_t;
    unsigned int width;
    unsigned int height;
    unsigned int grid_column;
    unsigned int grid_row;
    unsigned int grid_width;
    unsigned int grid_height;
} button_t;

// Create new: open_usb_button widget.
button_t *open_usb_button_new_widget(GtkWidget *windows);
// Create new: open_file_button widget.
button_t *open_file_button_new_widget(GtkWidget *windows);

// Callback event for handling: open_usb_button widget.
static void on_open_usb_button_clicked(GtkButton *open_usb_button, gpointer data);
// Callback event for handling: open_usb_dialog dialog.
static void on_open_usb_dialog(GtkDialog *dialog, int response_id, gpointer data);

// Callback event for handling: open_file_button widget.
static void on_open_file_button_clicked(GtkButton *open_file_button, gpointer data);
// Callback event for handling: open_file_dialog dialog.
static void on_open_file_dialog(GtkDialog *dialog, int response_id, gpointer data);

#endif // BUTTON_H