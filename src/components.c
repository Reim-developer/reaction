#include "components.h"
#include "dropbox.h"
#include "button.h"
#include "label.h"

void setup_ui_new(GtkWidget *windows_grid_t, GtkWidget *windows) {
    button_t *open_usb_btn_t = open_usb_button_new(windows);
    gtk_grid_attach(GTK_GRID(windows_grid_t),
        open_usb_btn_t->button,
        open_usb_btn_t->grid_column,
        open_usb_btn_t->grid_row,
        open_usb_btn_t->grid_width,
        open_usb_btn_t->grid_height
    );

    label_t *label_description_top = label_description_new();
    gtk_grid_attach(GTK_GRID(windows_grid_t), 
        label_description_top->label,
        label_description_top->grid_column,
        label_description_top->grid_row,
        label_description_top->grid_width,
        label_description_top->grid_height
    );

    dropbox_t *device_list_t = dropbox_set_new();
    gtk_grid_attach(GTK_GRID(windows_grid_t),
    device_list_t->dropbox, device_list_t->grid_column,
    device_list_t->grid_row, device_list_t->grid_width,
    device_list_t->grid_height
    );

    g_free(open_usb_btn_t);
    g_free(label_description_top);
    g_free(device_list_t);
}