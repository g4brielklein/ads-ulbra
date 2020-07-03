-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Jul 03, 2020 at 04:41 AM
-- Server version: 10.4.11-MariaDB
-- PHP Version: 7.4.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `AdmVendas`
--

-- --------------------------------------------------------

--
-- Table structure for table `categorias`
--

CREATE TABLE `categorias` (
  `CatCodigo` int(10) NOT NULL,
  `CatNome` varchar(100) NOT NULL,
  `CatGrupo` varchar(100) NOT NULL,
  `CatSubGrupo` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `categorias`
--

INSERT INTO `categorias` (`CatCodigo`, `CatNome`, `CatGrupo`, `CatSubGrupo`) VALUES
(1, 'ROUPA MASCULINA', 'ROUPA', 'MASCULINA'),
(2, 'ROUPA FEMININA', 'ROUPA', 'FEMININA'),
(3, 'VIDEOS', 'ACESSÓRIOS', 'VIDEOS'),
(4, 'SACO', 'ACESSÓRIOS', 'SACO'),
(5, 'PINGENTE', 'BIJOUTERIAS', 'PINGENTE'),
(6, 'DIVERSOS', 'GERAIS', 'INDIFERENTE'),
(7, 'DIVERSOS', 'GERAIS', ' '),
(8, 'VINHO TINTO', 'BEBIDAS', 'VINHOS E ESPUMANTES'),
(9, 'AGUARDENTE', 'BEBIDAS', 'DESTILADOS'),
(10, 'CONHAQUE', 'BEBIDAS', 'DESTILADOS'),
(11, 'LICOR', 'BEBIDAS', 'DESTILADOS'),
(12, 'WISKY', 'BEBIDAS', 'DESTILADOS'),
(13, 'VODKA', 'BEBIDAS', 'DESTILADOS'),
(14, 'CERVEJAS', 'BEBIDAS', 'CERVEJAS'),
(15, 'REFRIGERANTES', 'BEBIDAS', 'REFRIGERANTES'),
(16, 'ÁGUA', 'BEBIDAS', 'ÁGUA'),
(17, 'SUCOS', 'BEBIDAS', 'SUCOS'),
(18, 'CAFÉS/CHÁS', 'MERCEARIA', 'CAFÉS/CHÁS'),
(19, 'BALAS', 'BOMBONIERE', 'BALAS E AFINS'),
(20, 'PATILHAS', 'BOMBONIERE', 'BALAS E AFINS'),
(21, 'PIRULITOS', 'BOMBONIERE', 'BALAS E AFINS'),
(22, 'AVES', 'CARNES', 'AVES'),
(23, 'CARNES BOVINAS', 'CARNES', 'CARNES BOVINAS'),
(24, 'CARNES SUÍNAS', 'CARNES', 'CARNES SUÍNAS E OVINAS'),
(25, 'CARNES OVINAS', 'CARNES', 'CARNES SUÍNAS E OVINAS'),
(26, 'PEIXES', 'CARNES', 'PEIXES'),
(27, 'VINHO BRANCO', 'BEBIDAS', 'VINHOS E ESPUMANTES'),
(28, 'JOGOS', 'JOGOS', 'PC'),
(30, 'Teste', 'Teste', 'Teste'),
(32, 'Teste1', 'Teste1', 'Teste1');

-- --------------------------------------------------------

--
-- Table structure for table `clientes`
--

CREATE TABLE `clientes` (
  `CliCodigo` int(10) NOT NULL,
  `CliNome` varchar(100) NOT NULL,
  `CliCPF` varchar(20) NOT NULL,
  `CliCNPJ` varchar(20) DEFAULT NULL,
  `CliEndereco` varchar(100) NOT NULL,
  `CliBairro` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `clientes`
--

INSERT INTO `clientes` (`CliCodigo`, `CliNome`, `CliCPF`, `CliCNPJ`, `CliEndereco`, `CliBairro`) VALUES
(1, 'Gabriel Klein', '044.715.990-97', ' ', 'Rua Henrique Soares da Silva, 173', 'Vargas'),
(2, 'Edemar Oliveira', '044.765.432-21', ' ', 'Rua Canoas, 2009', 'Centro'),
(3, 'Sabrina Rodrigues', '003.337.879-95', ' ', 'Rua Vera Cruz, 312', 'Paraíso'),
(4, 'Marcia Fogaça', '004.335.970-45', ' ', 'Rua Santa Helena, 1515', 'Walderez'),
(5, 'Cristiano Alegre', ' ', '71.395.212/0001-63', 'Rua Jorge Assum, 767', 'Primor');

-- --------------------------------------------------------

--
-- Table structure for table `fornecedores`
--

CREATE TABLE `fornecedores` (
  `ForCodigo` int(10) NOT NULL,
  `ForNome` varchar(100) NOT NULL,
  `ForFantasia` varchar(100) NOT NULL,
  `ForCNPJ` varchar(100) NOT NULL,
  `ForEndereco` varchar(100) NOT NULL,
  `ForFone` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `fornecedores`
--

INSERT INTO `fornecedores` (`ForCodigo`, `ForNome`, `ForFantasia`, `ForCNPJ`, `ForEndereco`, `ForFone`) VALUES
(1, 'COMERCIO MARECHAL ROUPAS LTDA.', 'MARECHAL ROUPAS', '98.467.780/0001-89', 'Av João Pereira de Vargas', '34748912'),
(2, 'DISTRIBUIDOR DE BEBIDAS SHABASS LTDA.', 'BEBIDAS SHABASS', '78.437.720/0001-81', 'Rua São Sepé, 480', '34998765'),
(3, 'Noah e Laís Comercio de Bebidas ME', 'NL Bebidas', '37.278.011/0001-48', 'Rua Clarêncio Antônio da Silveira, 434', '(55) 3962-2100'),
(4, 'Pietro e Bárbara Alimentos ME', 'PB Alimentos', '35.973.588/0001-44', 'Rua Georgeta Fontinha Bardou Bento, 428', '(53) 3566-9966');

-- --------------------------------------------------------

--
-- Table structure for table `pessoa`
--

CREATE TABLE `pessoa` (
  `id` int(11) UNSIGNED NOT NULL,
  `nome` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `endereco` varchar(80) COLLATE utf8_unicode_ci NOT NULL,
  `telefone` varchar(35) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(40) COLLATE utf8_unicode_ci NOT NULL,
  `sexo` varchar(1) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `pessoa`
--

INSERT INTO `pessoa` (`id`, `nome`, `endereco`, `telefone`, `email`, `sexo`) VALUES
(6, 'Gabriel Klein', 'Rua Teste, 123', '(51) 998765433', 'gabrielklein@rede.ulbra.br', 'M');

-- --------------------------------------------------------

--
-- Table structure for table `produtos`
--

CREATE TABLE `produtos` (
  `ProCodigo` int(10) NOT NULL,
  `ProDescricao` varchar(100) NOT NULL,
  `CatCodigo` int(100) NOT NULL,
  `ProFornecedor` varchar(100) NOT NULL,
  `ProPrecoVenda` varchar(100) NOT NULL,
  `ProMargemLucro` varchar(100) NOT NULL,
  `ProEstoque` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `produtos`
--

INSERT INTO `produtos` (`ProCodigo`, `ProDescricao`, `CatCodigo`, `ProFornecedor`, `ProPrecoVenda`, `ProMargemLucro`, `ProEstoque`) VALUES
(1, 'Camiseta Guns n\'Roses Preta', 1, 'COMERCIO MARECHAL ROUPAS LTDA.', '59,90', '29,90', 50),
(2, 'Calça Rala Bella Cinza', 2, 'COMERCIO MARECHAL ROUPAS LTDA.', '119,90', '49,90', 20),
(3, 'Coca Cola 2l', 14, 'DISTRIBUIDOR DE BEBIDAS SHABASS LTDA.', '7,99', '3,99', 80),
(4, 'Café em Pó Melitta 500g', 18, 'DISTRIBUIDOR DE BEBIDAS SHABASS LTDA.', '10,19', '3,49', 37);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `categorias`
--
ALTER TABLE `categorias`
  ADD PRIMARY KEY (`CatCodigo`);

--
-- Indexes for table `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`CliCodigo`);

--
-- Indexes for table `pessoa`
--
ALTER TABLE `pessoa`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `pessoa`
--
ALTER TABLE `pessoa`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
