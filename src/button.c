#include "button.h"

button_t *open_usb_button_new() {
    button_t *open_usb_button = g_new(button_t, 1);
    open_usb_button->button = gtk_button_new_with_label("Choose USB...");
    open_usb_button->width = 10;
    open_usb_button->height = 20;
    open_usb_button->grid_column = 3;
    open_usb_button->grid_row = 5;
    open_usb_button->grid_width = 1;
    open_usb_button->grid_height = 1;

    gtk_widget_set_size_request(open_usb_button->button, open_usb_button->width, open_usb_button->height);

    return open_usb_button;
}