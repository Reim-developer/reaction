#include "button.h"
#include "dropbox.h"

button_t *open_usb_button_new(GtkWidget *windows) {
    button_t *open_usb_button = g_new(button_t, 1);
    open_usb_button->button = gtk_button_new_with_label("Choose USB...");

    open_usb_button->width = 10;
    open_usb_button->height = 20;

    open_usb_button->grid_column = 6;
    open_usb_button->grid_row = 5;

    open_usb_button->grid_width = 3;
    open_usb_button->grid_height = 1;

    open_usb_button->device_list_t = NULL;

    gtk_widget_set_size_request(open_usb_button->button, open_usb_button->width, open_usb_button->height);
    g_signal_connect(open_usb_button->button, "clicked", G_CALLBACK(open_usb_button_clicked), open_usb_button);
    return open_usb_button;
}

static void on_open_usb_dialog(GtkDialog *dialog, int response_id, gpointer data) {
    if(response_id == GTK_RESPONSE_ACCEPT) {
       button_t *open_usb_button_t = (button_t *) data;
       dropbox_t *device_list_t = open_usb_button_t->device_list_t;

       if (device_list_t == NULL) {
            g_warning("device_list_t is NULL. Stop program");
            return;
       }

       GtkFileChooser *file_chooser_t = GTK_FILE_CHOOSER(dialog);
       GFile *g_file_t = gtk_file_chooser_get_file(file_chooser_t);
       char *device_directory = g_file_t ? g_file_get_path(g_file_t) : NULL;

       if (device_directory == NULL) {
            printf("device_directory is NULL. Stop program");
            return;
       }
       char *device_name = g_path_get_basename(device_directory);

       GListModel *device_list_model_t = G_LIST_MODEL(gtk_string_list_new((const char *[]) {
            device_name, NULL
       }));

       device_list_t->device_model_list = device_list_model_t;
       gtk_drop_down_set_model(GTK_DROP_DOWN(device_list_t->dropbox), device_list_t->device_model_list);

       g_free(device_directory);
       g_free(device_name);
       g_object_unref(g_file_t);
    }
    gtk_window_close(GTK_WINDOW(dialog));
}

static void open_usb_button_clicked(GtkButton *button, gpointer data) {
    button_t *open_usb_button_t = (button_t *) data;
    dropbox_t *device_list_t = open_usb_button_t->device_list_t;

    GtkWindow *main_windows = GTK_WINDOW(gtk_widget_get_ancestor(GTK_WIDGET(button), GTK_TYPE_WINDOW));

    GtkWidget *choose_usb_dialog = g_object_new(
        GTK_TYPE_FILE_CHOOSER_DIALOG,
        "title", "Select BOOT USB",
        "transient-for", main_windows,
        "action", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, NULL
    );

    gtk_dialog_add_button(GTK_DIALOG(choose_usb_dialog), "Open", GTK_RESPONSE_ACCEPT);
    gtk_dialog_add_button(GTK_DIALOG(choose_usb_dialog), "Cancel", GTK_RESPONSE_CANCEL);

    g_signal_connect(choose_usb_dialog, "response", G_CALLBACK(on_open_usb_dialog), open_usb_button_t);
    gtk_window_present(GTK_WINDOW(choose_usb_dialog));
}