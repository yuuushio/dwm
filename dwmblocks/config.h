#define CMDLENGTH 60
#define DELIMITER " "
#define CLICKABLE_BLOCKS
#define DI "/home/y/.dwm/dwmblocks_scripts/riced_scripts/"

/** each block needs to have a unique sig ID if you want to update them using
 * signals **/
const Block blocks[] = {

    BLOCK(DI "left_bracket", 0, 0),    BLOCK(DI "d_memory", 5, 20),
    BLOCK(DI "d_mem_percent", 5, 21),  BLOCK(DI "right_bracket", 0, 0),

    BLOCK(DI "left_bracket", 0, 0),    BLOCK(DI "d_vol_icon", 20, 10),
    BLOCK(DI "d_progressbar", 20, 11), BLOCK(DI "d_vol_percent", 20, 12),
    BLOCK(DI "right_bracket", 0, 0),

    BLOCK(DI "left_bracket", 0, 0),    BLOCK(DI "d_bluetooth", 1, 13),
    BLOCK(DI "d_network", 5, 4),       BLOCK(DI "right_bracket", 0, 0),

    BLOCK(DI "left_bracket", 0, 0),    BLOCK(DI "d_date", 1, 14),
    BLOCK(DI "d_time", 1, 15),         BLOCK(DI "right_bracket", 0, 0)};
