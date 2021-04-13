<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'my_database' );

/** MySQL database username */
define( 'DB_USER', 'Kirill' );

/** MySQL database password */
define( 'DB_PASSWORD', 'root' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'k)#8n$)qZ@B-%#RY.K;;&LKoAsZIl![urnr=.UJl9(-;B!E1+msH@`P_3Zw0xV^J' );
define( 'SECURE_AUTH_KEY',  '19y+irp,ti{P)+9?FEc=/4++ul`;aMrOhN1]|5av&-J@EnD{7X+1$+rDd*(~=@.T' );
define( 'LOGGED_IN_KEY',    ';6reE4o3.^/*|M4U+Uw>re}690$4s~Z}TyKGI5R]b7Ugv-;mJ`$|-+n!d_@kc18G' );
define( 'NONCE_KEY',        'bg<?3?L?{+I0JIeWkGz9*Q8>IQzS=BQrbb|iYD.MU}U}tw5g#2-*?O+;OaZu:ll&' );
define( 'AUTH_SALT',        '--<Q::Q_B;4HwvwE@|q}*#B[/9_OA8ybDKxpShNNEqR/R|P9u$L*$|Wn?_(-yL8]' );
define( 'SECURE_AUTH_SALT', 'X@N,|.n){RS4gZ+3o-F,)v4wg0ZGYDeF|hq/1iHpuNg)8#pH|?mzI>8Ty94pFUF=' );
define( 'LOGGED_IN_SALT',   'HtB8u->$+8+A=M.s7D-:n{T@O:,;[E,~Y]?V <qXuKo&rlJ<_qM,)|G#Nv+1m-}S' );
define( 'NONCE_SALT',       'L@K?y-||hy60n]!+],cw|$n?-0!;O|.O}k1,+!%+Y{*-(RL%xeu1XP8etkg,6= Q' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
