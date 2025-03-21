#include "button.h"
#include "dropbox.h"
#include "panel.h"

static void on_open_usb_dialog(GtkDialog *dialog, int response_id, gpointer data) {
    if(response_id == GTK_RESPONSE_ACCEPT) {
       button_t *open_usb_button_t = (button_t *) data;
       dropbox_t *dropbox_data_t = open_usb_button_t->dropbox_data_t;

       GtkFileChooser *file_chooser_t = GTK_FILE_CHOOSER(dialog);
       GFile *g_file_t = gtk_file_chooser_get_file(file_chooser_t);
       char *device_directory = g_file_t ? g_file_get_path(g_file_t) : NULL;

       int text_view_status = is_default_text_view(open_usb_button_t->panel_text_view_t, DEFAULT_TEXT_CONTENT);
       char *device_name = g_path_get_basename(device_directory);
       char *fmt_content = g_strdup_printf("Selected device: %s", device_name);

       if(text_view_status == IS_DEFAULT_TEXT_VIEW) {
            result_text_clear_new(open_usb_button_t->panel_text_view_t);
            result_text_append_new(open_usb_button_t->panel_text_view_t, fmt_content);
       } else {
            result_text_append_new(open_usb_button_t->panel_text_view_t, fmt_content);
       }
       g_free(fmt_content);

       GListModel *device_list_model_t = G_LIST_MODEL(gtk_string_list_new((const char *[]) {
            device_name, NULL
       }));

       dropbox_data_t->device_model_list = device_list_model_t;
       gtk_drop_down_set_model(GTK_DROP_DOWN(dropbox_data_t->dropbox), dropbox_data_t->device_model_list);

       g_free(device_directory);
       g_free(device_name);
       g_object_unref(g_file_t);
    }
    gtk_window_close(GTK_WINDOW(dialog));
}

static void on_open_file_dialog(GtkDialog *dialog, int response_id, gpointer data) {
    if(response_id == GTK_RESPONSE_ACCEPT) {
        button_t *open_file_button_t = (button_t *) data;
        dropbox_t *boot_file_list_t =  open_file_button_t->dropbox_data_t;

        GtkFileChooser *file_chooser_t = GTK_FILE_CHOOSER(dialog);
        GFile *g_file_t = gtk_file_chooser_get_file(file_chooser_t);
        char *boot_file_path = g_file_t ? g_file_get_path(g_file_t) : NULL;
        int text_view_status = is_default_text_view(open_file_button_t->panel_text_view_t, DEFAULT_TEXT_CONTENT);

        if (g_file_test(boot_file_path, G_FILE_TEST_IS_DIR)) {
            char *fmt_content = g_strdup_printf(
                "Selected is not allowed: %s\nOnly support .iso or .img file formats", boot_file_path);

            if(text_view_status == IS_DEFAULT_TEXT_VIEW) {
                result_text_clear_new(open_file_button_t->panel_text_view_t);
                result_text_append_new(open_file_button_t->panel_text_view_t, fmt_content);
                g_free(fmt_content);
                return;
            }
            result_text_append_new(open_file_button_t->panel_text_view_t, fmt_content);
            
            g_free(fmt_content);
            return;
        }
        open_file_button_t->start_button->boot_file_path = g_strdup(boot_file_path);

        char *boot_file_name = g_path_get_basename(boot_file_path);
        char  *fmt_content = g_strdup_printf("Selected boot file successfully with name: %s", boot_file_name);

        if (text_view_status == IS_DEFAULT_TEXT_VIEW) {
            result_text_clear_new(open_file_button_t->panel_text_view_t);
            result_text_append_new(open_file_button_t->panel_text_view_t, fmt_content);
        } else {
            result_text_append_new(open_file_button_t->panel_text_view_t, fmt_content);
        }
        g_free(fmt_content);

        GListModel *boot_file_model_t = G_LIST_MODEL(gtk_string_list_new((const char *[]) {
            boot_file_name, NULL
        }));
        
        boot_file_list_t->device_model_list = boot_file_model_t;
        gtk_drop_down_set_model(GTK_DROP_DOWN(boot_file_list_t->dropbox), boot_file_list_t->device_model_list);

        g_free(boot_file_path);
        g_free(boot_file_name);
        g_object_unref(g_file_t);
    }
    gtk_window_close(GTK_WINDOW(dialog));
}

static void on_open_usb_button_clicked(GtkButton *button, gpointer data) {
    button_t *open_usb_button_t = (button_t *) data;

    GtkWindow *main_windows = GTK_WINDOW(gtk_widget_get_ancestor(GTK_WIDGET(button), GTK_TYPE_WINDOW));
    
    GtkFileChooserDialog *choose_usb_dialog = g_object_new(
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
    button_t *open_file_button_t = (button_t *) data;
    GtkWindow *main_windows = GTK_WINDOW(gtk_widget_get_ancestor(GTK_WIDGET(button), GTK_TYPE_WINDOW));

    GtkFileChooser *choose_file_dialog = g_object_new(
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

    g_signal_connect(choose_file_dialog, "response", G_CALLBACK(on_open_file_dialog), open_file_button_t);
    gtk_window_present(GTK_WINDOW(choose_file_dialog));
}

static void on_start_dialog(GtkDialog *dialog_t, int response, gpointer data_t) {
    gtk_window_destroy(GTK_WINDOW(dialog_t));
}

static void on_start_button_clicked(GtkButton *button, gpointer data_t) {
    button_t *start_button_t = (button_t *) data_t;
    GtkWindow *main_windows = GTK_WINDOW(
        gtk_widget_get_ancestor(GTK_WIDGET(button), 
        GTK_TYPE_WINDOW
    ));

    GFile *file_t = g_file_new_for_path(start_button_t->boot_file_path);
    if(!g_file_query_exists(file_t, NULL)) {
        GtkWidget *dialog_t = gtk_message_dialog_new(
            main_windows, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
            GTK_BUTTONS_OK, "Please choose valid boot file"
        );
        gtk_window_present(GTK_WINDOW(dialog_t));
        g_signal_connect(dialog_t, "response", G_CALLBACK(on_start_dialog), NULL);
        return;
    }
    
    g_print("%s\n", start_button_t->boot_file_path);
}

button_t *open_usb_button_new_widget(GtkWidget *windows) {
    button_t *open_usb_button_t = g_new(button_t, 1);
    open_usb_button_t->button = gtk_button_new_with_label("Choose USB...");

    open_usb_button_t->width = 20;
    open_usb_button_t->height = 1;

    open_usb_button_t->grid_column = 9;
    open_usb_button_t->grid_row = 5;

    open_usb_button_t->grid_width = 5;
    open_usb_button_t->grid_height = 1;

    open_usb_button_t->dropbox_data_t = NULL;

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

    open_file_button_t->dropbox_data_t = NULL;

    gtk_widget_set_size_request(open_file_button_t->button, open_file_button_t->width, open_file_button_t->height);
    g_signal_connect(open_file_button_t->button, "clicked", G_CALLBACK(on_open_file_button_clicked), open_file_button_t);

    return open_file_button_t;
}

button_t *start_button_new_widget(GtkWidget *windows) {
    button_t *start_button_t = g_new(button_t, 1);
    start_button_t->button = gtk_button_new_with_label("Start");

    start_button_t->width = 20;
    start_button_t->height = 1;

    start_button_t->grid_column = 15;
    start_button_t->grid_row = 11;

    start_button_t->grid_width = 20;
    start_button_t->grid_height = 1;

    gtk_widget_set_size_request(start_button_t->button, start_button_t->width, start_button_t->height);

    g_signal_connect(start_button_t->button, "clicked", G_CALLBACK(on_start_button_clicked), start_button_t);
    return start_button_t;
}

