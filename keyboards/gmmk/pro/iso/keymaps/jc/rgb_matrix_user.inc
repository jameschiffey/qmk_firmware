RGB_MATRIX_EFFECT(SIDE_LIGHTS)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool SIDE_LIGHTS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    rgb_matrix_set_color_all(0x00, 0x00, 0x0);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);

    // Left
    rgb_matrix_set_color(68, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(71, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(74, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(77, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(81, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(84, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(88, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(92, rgb.r, rgb.g, rgb.b);

    // Right
    rgb_matrix_set_color(69, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(72, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(75, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(78, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(82, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(85, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(89, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(93, rgb.r, rgb.g, rgb.b);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS


// RGB LED layout ISO

// led number, function of the key

//  68, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      70, Prt       			   Rotary(Mute)   69, Side led 12
//  71, Side led 02    1, `~       7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       79, (=+)     86, BackSpc   		     73, Del          72, Side led 13
//  74, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       90, ]}                     			   76, PgUp       75, Side led 14
//  77, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"       95, #        97, Enter     			   87, PgDn       78, Side led 15
//  81, Side led 05    4, Sh_L     67,\		     10, Z        16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?             		    91, Sh_R     94, Up    83, End        82, Side led 16
//  84, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              			   33, SPACE                              	  49, Alt_R    55, FN       65, Ct_R                  96, Left     98, Down  80, Right        85, Side led 17
//  88, Side led 07                                                                                                                                                                                                        		    	  89, Side led 18
//  92, Side led 08                                                                                                                                                                                                        			      93, Side led 19
