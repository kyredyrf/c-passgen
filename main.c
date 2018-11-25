#include "app.h"
#include <stdio.h>

int main(int argc, const char* argv[])
{
	app_t* app;

	/* 画面消去 */
	/*puts("\x1b[2J");*/
	/*system("clear");*/

	/*printf("%016lx\n", get_hash_value("hoge"));*/
	app = app_create();
#if 1
	app_parse_arguments(app, argc, argv);
#else
	app_set_use_char(app, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
	app_set_keyword(app, "hoge");
	app_set_encode_count(app, 8);
#endif
	fputs("Content-type: text/plain\n\n", stdout);
	fputs(app_encode(app), stdout);
	app_destroy(app);
	return 0;
}
