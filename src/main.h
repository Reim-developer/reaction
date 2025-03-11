#ifndef MAIN_H
#define MAIN_H
#include <gtk/gtk.h>

typedef struct {
    char *app_name;
    char *app_version;
    unsigned  app_width;
    unsigned int app_height;
} app_property_t;

static void on_app_open(GtkApplication *g_app, gpointer data);

#endif // MAIN_H