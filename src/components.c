#include "components.h"
#include "dropbox.h"
#include "button.h"
#include "label.h"

void setup_ui_new(GtkWidget *windows_grid_t) {
    button_t *open_usb_btn_t = open_usb_button_new();
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

    g_free(open_usb_btn_t);
    g_free(label_description_top);
}