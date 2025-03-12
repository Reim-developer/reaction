#include "button.h"
#include "dropbox.h"

button_t *open_usb_button_new_widget(GtkWidget *windows) {
    button_t *open_usb_button_t = g_new(button_t, 1);
    open_usb_button_t->button = gtk_button_new_with_label("Choose USB...");

    open_usb_button_t->width = 20;
    open_usb_button_t->height = 1;

    open_usb_button_t->grid_column = 9;
    open_usb_button_t->grid_row = 5;

    open_usb_button_t->grid_width = 5;
    open_usb_button_t->grid_height = 1;

    open_usb_button_t->device_list_t = NULL;

    gtk_widget_set_size_request(open_usb_button_t->button, open_usb_button_t->width, open_usb_button_t->height);
    g_signal_connect(open_usb_button_t->button, "clicked", G_CALLBACK(on_open_usb_button_clicked), open_usb_button_t);
    return open_usb_button_t;
}

button_t *open_file_button_new_widget(GtkWidget *windows) {
    button_t *open_file_button_t = g_new(button_t, 1);
    open_file_button_t->button = gtk_button_new_with_label("Boot file seclection");
    
    open_file_button_t->width = 20;
    open_file_button_t->height = 1;

    open_file_button_t->grid_column = 30;
    open_file_button_t->grid_row = 5;

    open_file_button_t->grid_width = 5;
    open_file_button_t->grid_height = 1;

    gtk_widget_set_size_request(open_file_button_t->button, open_file_button_t->width, open_file_button_t->height);
    g_signal_connect(open_file_button_t->button, "clicked", G_CALLBACK(on_open_file_button_clicked), NULL);

    return open_file_button_t;
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

static void on_open_usb_button_clicked(GtkButton *button, gpointer data) {
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

static void on_open_file_button_clicked(GtkButton *button, gpointer data) {
    GtkWindow *main_windows = GTK_WINDOW(gtk_widget_get_ancestor(GTK_WIDGET(button), GTK_TYPE_WINDOW));

    GtkFileChooserDialog *choose_file_dialog = g_object_new(
        GTK_TYPE_FILE_CHOOSER_DIALOG,
        "title", "Selection BOOT File",
        "transient-for", main_windows,
        "action", GTK_FILE_CHOOSER_ACTION_OPEN, NULL
    );

    gtk_dialog_add_button(GTK_DIALOG(choose_file_dialog), "Select", GTK_RESPONSE_ACCEPT);
    gtk_dialog_add_button(GTK_DIALOG(choose_file_dialog), "Cancel", GTK_RESPONSE_CANCEL);

    GtkFileFilter *filter_file_t = gtk_file_filter_new();
    gtk_file_filter_add_pattern(filter_file_t, "*.iso");
    gtk_file_filter_add_pattern(filter_file_t, "*.img");
    gtk_file_filter_set_name(filter_file_t, "Boot File (*.iso, *.img)");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(choose_file_dialog), filter_file_t);

    g_signal_connect(choose_file_dialog, "response", G_CALLBACK(on_open_file_dialog), NULL);
    gtk_window_present(GTK_WINDOW(choose_file_dialog));
}

static void on_open_file_dialog(GtkDialog *dialog, int response_id, gpointer data) {
    if(response_id == GTK_RESPONSE_ACCEPT) {
        // TODO: Setup event handling for this callback
    }
    gtk_window_close(GTK_WINDOW(dialog));
}