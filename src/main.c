#include <gtk/gtk.h>
#include "main.h"
#include "button.h"
#include "label.h"

static void on_app_open(GtkApplication *g_app, gpointer gpointer_data) {
    app_property_t *app_info_t = (app_property_t *) gpointer_data;
    
    app_info_t->app_name = "reaction!";
    app_info_t->app_height = 600;
    app_info_t->app_width = 600;

    GtkWidget *window = gtk_application_window_new(g_app);
    gtk_window_set_title(GTK_WINDOW(window), app_info_t->app_name);
    gtk_window_set_default_size(GTK_WINDOW(window), app_info_t->app_width, app_info_t->app_height);

    GtkWidget *window_grid_t = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(window_grid_t), 10);
    gtk_grid_set_column_spacing(GTK_GRID(window_grid_t), 10);
    gtk_window_set_child(GTK_WINDOW(window), window_grid_t);

    button_t *open_usb_btn_t = open_usb_button_new();
    gtk_grid_attach(GTK_GRID(window_grid_t),
        open_usb_btn_t->button,
        open_usb_btn_t->grid_column,
        open_usb_btn_t->grid_row,
        open_usb_btn_t->grid_width,
        open_usb_btn_t->grid_height
    );

    label_t *label_description_top = label_description_new();
    gtk_grid_attach(GTK_GRID(window_grid_t), 
        label_description_top->label,
        label_description_top->grid_column,
        label_description_top->grid_row,
        label_description_top->grid_width,
        label_description_top->grid_height
    );

    gtk_widget_show(window);
    g_free(open_usb_btn_t);
    g_free(label_description_top);
}

int main(int argc, char *argv[]) {
    app_property_t p;

    GtkApplication *app = gtk_application_new("com.reim.dev", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_app_open), &p);
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}
