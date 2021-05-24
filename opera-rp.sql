-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 24-05-2021 a las 03:13:16
-- Versión del servidor: 10.4.13-MariaDB
-- Versión de PHP: 7.3.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `db`
--

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
  PRIMARY KEY (`id`),
  KEY `type` (`type`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `doors`
--

INSERT INTO `doors` (`id`, `name`, `type`, `int_freeze`, `int_mapicon`, `int_world`, `int_interior`, `int_posx`, `int_posy`, `int_posz`, `int_posa`, `ext_freeze`, `ext_mapicon`, `ext_world`, `ext_interior`, `ext_posx`, `ext_posy`, `ext_posz`, `ext_posa`, `time_open`, `time_close`, `actorid`) VALUES
(1, '24/7', 7, 0, -1, 0, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2194.73, 1991.02, 12.2969, 90, 0, 0, -1),
(2, '24/7', 7, 0, -1, 1, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, -180.966, 1034.82, 19.7422, 90, 0, 0, -1),
(3, '24/7', 7, 0, -1, 2, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1352.31, -1758.96, 13.5078, 0, 0, 0, -1),
(4, '24/7', 7, 0, -1, 3, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1833.54, -1842.54, 13.5781, 90, 0, 0, -1),
(5, '24/7', 7, 0, -1, 4, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2884.69, 2453.87, 11.069, 225, 0, 0, -1),
(6, '24/7', 7, 0, -1, 5, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2097.62, 2224.08, 11.0234, 180, 0, 0, -1),
(7, '24/7', 7, 0, -1, 6, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2247.65, 2396.42, 10.8203, 0, 0, 0, -1),
(8, '24/7', 7, 0, -1, 7, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1315.45, -897.967, 39.5781, 180, 0, 0, -1),
(9, '24/7', 7, 0, -1, 8, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1000.32, -919.933, 42.3281, 105, 0, 0, -1),
(10, '24/7', 7, 0, -1, 9, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2452.57, 2064.92, 10.8203, 180, 0, 0, -1),
(11, '24/7', 7, 0, -1, 10, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 2546.5, 1972.4, 10.8203, 180, 0, 0, -1),
(12, '24/7', 7, 0, -1, 11, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, 1937.59, 2307.27, 10.8203, 90, 0, 0, -1),
(13, '24/7', 7, 0, -1, 12, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, -1562.44, -2733.19, 48.7435, 234, 0, 0, -1),
(14, '24/7', 7, 0, -1, 13, 18, -30.9588, -91.8074, 1003.55, 0, 0, 17, 0, 0, -2442.72, 755.317, 35.1719, 180, 0, 0, -1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `doors_type`
--

DROP TABLE IF EXISTS `doors_type`;
CREATE TABLE IF NOT EXISTS `doors_type` (
  `id` tinyint(4) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=23 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `doors_type`
--

INSERT INTO `doors_type` (`id`, `name`) VALUES
(1, 'Binco'),
(2, 'SubUrban'),
(3, 'ProLaps'),
(4, 'Didier Sachs'),
(5, 'Victim'),
(6, 'ZIP'),
(7, '24/7'),
(8, 'Well Stacked Pizza'),
(9, 'Cluckin Bell'),
(10, 'BurgerShot'),
(11, 'Bank LS'),
(12, 'Bank SF'),
(13, 'Bank LV'),
(14, 'City Halls LS'),
(15, 'Unity Station'),
(16, 'Police LS'),
(17, 'Police SF'),
(18, 'Police LV'),
(19, 'Police Garage'),
(20, 'Club Alhambra'),
(21, 'Hostpital'),
(22, 'Club');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `player`
--

DROP TABLE IF EXISTS `player`;
CREATE TABLE IF NOT EXISTS `player` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(24) NOT NULL,
  `Password` varchar(65) NOT NULL,
  `Salt` varchar(16) NOT NULL,
  `Email` varchar(32) NOT NULL,
  `Gender` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `player`
--

INSERT INTO `player` (`ID`, `Name`, `Password`, `Salt`, `Email`, `Gender`) VALUES
(1, 'Moises_Gomez', '965CF0EA2DCC276F1DDD5B576CC60BE52E4267BA99E82A0E5C746C44A40BB58D', '0EF71bSUkj5lV86', 'dannyjp49@gmail.com', 0),
(2, 'Danyon_Joshep', '623969A082A6636A9D1600D176B0E480A67E0D26F02765D905423584D47DF102', '44693dTKk6z5e8k', 'dannyjp48@gmail.com', 0);

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
-- Filtros para la tabla `doors`
--
ALTER TABLE `doors`
  ADD CONSTRAINT `doors_ibfk_1` FOREIGN KEY (`type`) REFERENCES `doors_type` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;
COMMIT;

ALTER TABLE `properties`
  ADD CONSTRAINT `properties_ibfk_1` FOREIGN KEY (`owner`) REFERENCES `player` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;