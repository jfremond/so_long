/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:45:21 by jfremond          #+#    #+#             */
/*   Updated: 2021/12/08 15:13:01 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define ERR_PROG_USAGE "Usage : ./so_long map.ber\n"
# define ERR_FILE_EXIST "File doesn't exist\n"
# define ERR_FILE_DIRECTORY "File is a directory\n"
# define ERR_FILE_EXTENSION "File has the wrong extension\n"
# define ERR_FILE_NAME "File can't just be named .ber\n"

# define ERR_MAP_CLOSE "Map not closed\n"
# define ERR_MAP_SMALL "Map too small\n"
# define ERR_MAP_RECT "Map not rectangular\n"
# define ERR_MAP_CHAR "Wrong char in map\n"
# define ERR_MAP_PLAYER "No player or too many players\n"
# define ERR_MAP_COLL "No collectibles\n"
# define ERR_MAP_EXIT "No exit or too many exits\n"
# define ERR_MAP_BIG "Map too big\n"

# define ERR_TEXT "Invalid texture\n"

# define ERR_TILE_SIZE "The tile_size value must be of 32\n"

#endif
