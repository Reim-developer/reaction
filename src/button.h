// Define:
// Button widget.
// Button callback event.
// Dialog callback event. (Open when clicked a button widget).
#ifndef BUTTON_H
#define BUTTON_H
#include "dropbox.h"
#include "panel.h"
#include <gtk/gtk.h>

struct button_t;

// Button widget struct.
typedef struct button_t {
    GtkWidget *button;
    dropbox_t *dropbox_data_t;
    panel_t *panel_text_view_t;
    int width;
    int height;
    int grid_column;
    int grid_row;
    int grid_width;
    int grid_height;
    char *boot_file_path;
    struct button_t *start_button;
} button_t;

// Create new: open_usb_button widget.
button_t *open_usb_button_new_widget(GtkWidget *windows);
// Create new: open_file_button widget.
button_t *open_file_button_new_widget(GtkWidget *windows);
// Create new: start_button widget.
button_t *start_button_new_widget(GtkWidget *windows);

#endif // BUTTON_H
