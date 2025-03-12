#include <gtk/gtk.h>
#include "main.h"
#include "components.h"

static void on_app_open(GtkApplication *g_app, gpointer gpointer_data) {
    app_property_t *app_info_t = (app_property_t *) gpointer_data;
    
    app_info_t->app_name = "reaction!";
    app_info_t->app_height = 600;
    app_info_t->app_width = 600;

    GtkWidget *window = gtk_application_window_new(g_app);
    gtk_window_set_title(GTK_WINDOW(window), app_info_t->app_name);
    gtk_window_set_default_size(GTK_WINDOW(window), app_info_t->app_width, app_info_t->app_height);

    GtkWidget *window_grid_t = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(window_grid_t), 20);
    gtk_grid_set_column_spacing(GTK_GRID(window_grid_t), 20);
    gtk_window_set_child(GTK_WINDOW(window), window_grid_t);

    setup_ui_new(window_grid_t, window);
    gtk_widget_show(window);
}

int main(int argc, char *argv[]) {
    app_property_t p;

    GtkApplication *app = gtk_application_new("com.reim.dev", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_app_open), &p);
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}
