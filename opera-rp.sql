-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 20-05-2021 a las 16:05:46
-- Versión del servidor: 10.5.7-MariaDB
-- Versión de PHP: 7.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `opera-rp`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `player`
--

DROP TABLE IF EXISTS `player`;
CREATE TABLE IF NOT EXISTS `player` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(24) NOT NULL,
  `password` varchar(65) NOT NULL,
  `salt` varchar(16) NOT NULL,
  `email` varchar(32) NOT NULL,
  `gender` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `doors`
--

DROP TABLE IF EXISTS `doors`;
CREATE TABLE IF NOT EXISTS `doors` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `type` tinyint(4) NOT NULL,
  `int_freeze` tinyint(1) NOT NULL,
  `int_mapicon` tinyint(4) NOT NULL,
  `int_world` tinyint(4) NOT NULL,
  `int_interior` tinyint(4) NOT NULL,
  `int_posx` float NOT NULL,
  `int_posy` float NOT NULL,
  `int_posz` float NOT NULL,
  `int_posa` float NOT NULL,
  `ext_freeze` tinyint(1) NOT NULL,
  `ext_mapicon` tinyint(4) NOT NULL,
  `ext_world` tinyint(4) NOT NULL,
  `ext_interior` tinyint(4) NOT NULL,
  `ext_posx` float NOT NULL,
  `ext_posy` float NOT NULL,
  `ext_posz` float NOT NULL,
  `ext_posa` float NOT NULL,
  `time_open` tinyint(4) NOT NULL,
  `time_close` tinyint(4) NOT NULL,
  `actorid` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `doors`
--

INSERT INTO `doors` (`id`, `name`, `type`, `int_freeze`, `int_mapicon`, `int_world`, `int_interior`, `int_posx`, `int_posy`, `int_posz`, `int_posa`, `ext_freeze`, `ext_mapicon`, `ext_world`, `ext_interior`, `ext_posx`, `ext_posy`, `ext_posz`, `ext_posa`, `actorid`) VALUES
(1, '24/7', 7, 0, -1, 0, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2194.73, 1991.02, 12.2969, 90, -1),
(2, '24/7', 7, 0, -1, 1, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, -180.966, 1034.82, 19.7422, 90, -1),
(3, '24/7', 7, 0, -1, 2, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1352.31, -1758.96, 13.5078, 0, -1),
(4, '24/7', 7, 0, -1, 3, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1833.54, -1842.54, 13.5781, 90, -1),
(5, '24/7', 7, 0, -1, 4, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2884.69, 2453.87, 11.069, 225, -1),
(6, '24/7', 7, 0, -1, 5, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2097.62, 2224.08, 11.0234, 180, -1),
(7, '24/7', 7, 0, -1, 6, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2247.65, 2396.42, 10.8203, 0, -1),
(8, '24/7', 7, 0, -1, 7, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1315.45, -897.967, 39.5781, 180, -1),
(9, '24/7', 7, 0, -1, 8, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1000.32, -919.933, 42.3281, 105, -1),
(10, '24/7', 7, 0, -1, 9, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2452.57, 2064.92, 10.8203, 180, -1),
(11, '24/7', 7, 0, -1, 10, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2546.5, 1972.4, 10.8203, 180, -1),
(12, '24/7', 7, 0, -1, 11, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1937.59, 2307.27, 10.8203, 90, -1),
(13, '24/7', 7, 0, -1, 12, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, -1562.44, -2733.19, 48.7435, 234, -1),
(14, '24/7', 7, 0, -1, 13, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, -2442.72, 755.317, 35.1719, 180, -1);
COMMIT;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `properties`
--

DROP TABLE IF EXISTS `properties`;
CREATE TABLE IF NOT EXISTS `properties` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `owner` int(11) DEFAULT NULL,
  `lock_door` tinyint(1) NOT NULL DEFAULT 0,
  `price` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `rot` float NOT NULL,
  `pos_x` float NOT NULL,
  `pos_y` float NOT NULL,
  `pos_z` float NOT NULL,
  PRIMARY KEY (`id`),
  KEY `owner` (`owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `properties`
--
ALTER TABLE `properties`
  ADD CONSTRAINT `properties_ibfk_1` FOREIGN KEY (`owner`) REFERENCES `player` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
