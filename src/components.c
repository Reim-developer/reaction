#include "components.h"
#include "dropbox.h"
#include "button.h"
#include "label.h"
#include "panel.h"

void setup_ui_new(GtkWidget *windows_grid_t, GtkWidget *windows) {
    button_t *open_usb_btn_t = open_usb_button_new_widget(windows);
    gtk_grid_attach(GTK_GRID(windows_grid_t),
        open_usb_btn_t->button,
        open_usb_btn_t->grid_column,
        open_usb_btn_t->grid_row,
        open_usb_btn_t->grid_width,
        open_usb_btn_t->grid_height
    );

    button_t *open_file_button_t = open_file_button_new_widget(windows);
    gtk_grid_attach(GTK_GRID(windows_grid_t),
        open_file_button_t->button, open_file_button_t->grid_column,
        open_file_button_t->grid_row, open_file_button_t->grid_width,
        open_file_button_t->grid_height
    );

    button_t *start_button_t = start_button_new_widget(windows);
    gtk_grid_attach(GTK_GRID(windows_grid_t),
        start_button_t->button, start_button_t->grid_column,
        start_button_t->grid_row, start_button_t->grid_width,
        start_button_t->grid_height
    );

    label_t *label_description_top = label_description_new();
    gtk_grid_attach(GTK_GRID(windows_grid_t), 
        label_description_top->label,
        label_description_top->grid_column,
        label_description_top->grid_row,
        label_description_top->grid_width,
        label_description_top->grid_height
    );

    dropbox_t *device_list_t = device_dropbox_new();
    gtk_grid_attach(GTK_GRID(windows_grid_t),
    device_list_t->dropbox, device_list_t->grid_column,
    device_list_t->grid_row, device_list_t->grid_width,
    device_list_t->grid_height
    );

    dropbox_t *file_list_t = list_file_dropbox_new();
    gtk_grid_attach(GTK_GRID(windows_grid_t), 
        file_list_t->dropbox, file_list_t->grid_column,
        file_list_t->grid_row, file_list_t->width, file_list_t->height
    );

    panel_t *text_result_view_t = result_panel_widget_new();
    gtk_grid_attach(GTK_GRID(windows_grid_t),
        text_result_view_t->panel_area_t, text_result_view_t->grid_column,
        text_result_view_t->grid_row, text_result_view_t->grid_width,
        text_result_view_t->grid_height
    );

    open_usb_btn_t->dropbox_data_t = device_list_t;
    open_file_button_t->dropbox_data_t = file_list_t;
    open_file_button_t->panel_text_view_t = text_result_view_t;
}
