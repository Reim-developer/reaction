#include "button.h"

button_t *open_usb_button_new(GtkWidget *windows) {
    button_t *open_usb_button = g_new(button_t, 1);
    open_usb_button->button = gtk_button_new_with_label("Choose USB...");

    open_usb_button->width = 10;
    open_usb_button->height = 20;

    open_usb_button->grid_column = 4;
    open_usb_button->grid_row = 10;

    open_usb_button->grid_width = 1;
    open_usb_button->grid_height = 1;

    gtk_widget_set_size_request(open_usb_button->button, open_usb_button->width, open_usb_button->height);
    g_signal_connect(open_usb_button->button, "clicked", G_CALLBACK(open_usb_button_clicked), windows);
    return open_usb_button;
}

static void on_open_usb_dialog(GtkDialog *dialog, int response_id, gpointer data) {
    if(response_id == GTK_RESPONSE_ACCEPT) {
       printf("Working\n");
       return;
    }
    gtk_window_close(GTK_WINDOW(dialog));
}

void open_usb_button_clicked(GtkButton *button, gpointer data) {
    GtkWindow *main_windows = GTK_WINDOW(data);

    GtkWidget *choose_usb_dialog = g_object_new(
        GTK_TYPE_FILE_CHOOSER_DIALOG,
        "title", "Select BOOT USB",
        "transient-for", main_windows,
        "action", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, NULL
    );

    gtk_dialog_add_button(GTK_DIALOG(choose_usb_dialog), "Open", GTK_RESPONSE_ACCEPT);
    gtk_dialog_add_button(GTK_DIALOG(choose_usb_dialog), "Cancel", GTK_RESPONSE_CANCEL);

    g_signal_connect(choose_usb_dialog, "response", G_CALLBACK(on_open_usb_dialog), NULL);
    gtk_window_present(GTK_WINDOW(choose_usb_dialog));
}