#include <string.h>
#include <stdio.h>
#include <gio/gio.h>

// gcc gio_test.c -fpie -pie -o gio_test $(pkg-config --cflags --libs glib-2.0 gobject-2.0 gio-2.0)

void test()
{
   GFile *my_file = NULL;
   my_file = g_file_new_for_path("/home/uos/Desktop/test");
   g_assert_nonnull (my_file);

  /* But then querying its path should indicate it’s invalid. */
  // g_assert_null (g_file_get_path (file));
  // g_assert_null (g_file_get_basename (file));
  // g_assert_null (g_file_get_parent (file));
  g_autoptr(GError) local_error = NULL;
  if (!g_file_delete (my_file, NULL, &local_error) &&
    !g_error_matches (local_error, G_IO_ERROR, G_IO_ERROR_NOT_FOUND))
  {
    // deletion failed for some reason other than the file not existing:
    // so report the error
    g_warning ("Failed to delete %s: %s",
               g_file_peek_path (my_file), local_error->message);
  }
  g_object_unref (my_file);
}

int main () {
   test();
   return 0;
}