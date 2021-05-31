-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 29-05-2021 a las 12:24:26
-- Versión del servidor: 10.5.7-MariaDB
-- Versión de PHP: 7.4.16

SET FOREIGN_KEY_CHECKS=0;
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
-- Estructura de tabla para la tabla `doors`
--

DROP TABLE IF EXISTS `doors`;
CREATE TABLE IF NOT EXISTS `doors` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `interior` int(11) NOT NULL,
  `int_freeze` tinyint(1) NOT NULL DEFAULT 0,
  `int_world` tinyint(4) NOT NULL DEFAULT 0,
  `ext_freeze` tinyint(1) NOT NULL DEFAULT 0,
  `ext_mapicon` tinyint(4) NOT NULL,
  `ext_posx` float NOT NULL,
  `ext_posy` float NOT NULL,
  `ext_posz` float NOT NULL,
  `ext_posa` float NOT NULL,
  `time_open` tinyint(4) NOT NULL DEFAULT 0,
  `time_close` tinyint(4) NOT NULL DEFAULT 0,
  `actorid` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `interior` (`interior`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `doors_type`
--

DROP TABLE IF EXISTS `doors_type`;
CREATE TABLE IF NOT EXISTS `doors_type` (
  `id` tinyint(4) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=24 DEFAULT CHARSET=utf8;

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
(22, 'Club'),
(23, 'House');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `interiors`
--

DROP TABLE IF EXISTS `interiors`;
CREATE TABLE IF NOT EXISTS `interiors` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(60) NOT NULL,
  `interior_id` int(11) NOT NULL DEFAULT 0,
  `type` tinyint(4) DEFAULT NULL,
  `slot` int(11) NOT NULL DEFAULT 0,
  `int_x` float NOT NULL,
  `int_y` float NOT NULL,
  `int_z` float NOT NULL,
  `int_rot` float NOT NULL,
  PRIMARY KEY (`id`),
  KEY `type` (`type`)
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `interiors`
--

INSERT INTO `interiors` (`id`, `name`, `interior_id`, `type`, `slot`, `int_x`, `int_y`, `int_z`, `int_rot`) VALUES
(1, '24/7 v-1', 17, 7, 0, -25.722, -187.822, 1003.55, 0),
(2, '24/7 v-2 large', 10, 7, 1, 6.19614, -30.9165, 1003.55, 358.868),
(3, '24/7 v-3', 18, 7, 2, -30.9647, -91.9342, 1003.55, 0.121947),
(4, '24/7 v-4', 16, 7, 3, -26.1856, -140.916, 1003.55, 0.121947),
(5, '24/7 v-5', 4, 7, 4, -27.3827, -30.7948, 1003.56, 4.50833),
(6, '24/7 v-6', 6, 7, 5, -27.415, -57.5029, 1003.55, 3.25498),
(7, 'bulglary house 1', 3, 23, 6, 235.268, 1187.28, 1080.26, 359.832),
(8, 'bulglary house 2', 2, 23, 7, 226.233, 1239.94, 1082.14, 90.0488),
(9, 'bulglary house 3', 1, 23, 8, 226.775, 1289.93, 1082.13, 88.1688),
(10, 'bulglary house 4', 5, 23, 9, 226.652, 1114.31, 1080.99, 269.857),
(11, 'bulglary house 5', 15, 23, 10, 295.089, 1472.75, 1080.26, 0.701092),
(12, 'bulglary house 6', 2, 23, 11, 447.085, 1397.67, 1084.3, 357.255),
(13, 'bulglary house 7', 5, 23, 12, 226.863, 1114.27, 1081, 276.054),
(14, 'bulglary house 8', 4, 23, 13, 261.004, 1284.73, 1080.26, 358.124),
(15, 'bulglary house 9', 10, 23, 14, 23.9407, 1340.89, 1084.38, 358.461),
(16, 'bulglary house 10', 4, 23, 15, 221.879, 1141.32, 1082.61, 359.378),
(17, 'bulglary house 11', 4, 23, 16, -261.207, 1456.62, 1084.37, 93.6684),
(18, 'bulglary house 12', 5, 23, 17, 22.7225, 1403.98, 1084.43, 5.62086),
(19, 'bulglary house 13', 5, 23, 18, 140.362, 1366.76, 1083.86, 359.98),
(20, 'bulglary house 14', 6, 23, 19, 234.223, 1064.27, 1084.21, 358.391),
(21, 'bulglary house 15', 6, 23, 20, -68.85, 1351.63, 1080.21, 0.920898),
(22, 'bulglary house 16', 15, 23, 21, -283.727, 1470.95, 1084.38, 94.2718),
(23, 'bulglary house 17', 8, 23, 22, 2365.24, -1135.35, 1050.88, 2.77763),
(24, 'bulglary house 18', 8, 23, 23, -42.5468, 1405.94, 1084.43, 0.269795),
(25, 'bulglary house 19', 9, 23, 24, 83.0557, 1322.48, 1083.87, 1.21095),
(26, 'bulglary house 20', 9, 23, 25, 260.742, 1238.23, 1084.26, 1.21095),
(27, 'Rider house', 2, 23, 26, 2468.42, -1698.27, 1013.51, 88.8191),
(28, 'CJ house', 3, 23, 27, 2496, -1692.54, 1014.74, 180.627);

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
  `interior` int(11) NOT NULL,
  `rot` float NOT NULL,
  `pos_x` float NOT NULL,
  `pos_y` float NOT NULL,
  `pos_z` float NOT NULL,
  PRIMARY KEY (`id`),
  KEY `owner` (`owner`),
  KEY `interior` (`interior`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `doors`
--
ALTER TABLE `doors`
  ADD CONSTRAINT `doors_ibfk_2` FOREIGN KEY (`interior`) REFERENCES `interiors` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `interiors`
--
ALTER TABLE `interiors`
  ADD CONSTRAINT `interiors_ibfk_1` FOREIGN KEY (`type`) REFERENCES `doors_type` (`id`) ON DELETE SET NULL ON UPDATE CASCADE;

--
-- Filtros para la tabla `properties`
--
ALTER TABLE `properties`
  ADD CONSTRAINT `properties_ibfk_1` FOREIGN KEY (`owner`) REFERENCES `player` (`ID`) ON DELETE SET NULL ON UPDATE CASCADE,
  ADD CONSTRAINT `properties_ibfk_2` FOREIGN KEY (`interior`) REFERENCES `interiors` (`id`) ON UPDATE CASCADE;
SET FOREIGN_KEY_CHECKS=1;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
