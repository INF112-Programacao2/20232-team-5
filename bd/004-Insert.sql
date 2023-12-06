INSERT INTO public."USUARIO"(
	"NOME", "APELIDO", "SEXO", "LOGIN", "SENHA")
	VALUES ('Arlindão', 'Bola de Fogo', 'M', 'adm', 'adm',);

INSERT INTO public."MODALIDADE"(
	"CHAVEMOD", "NOME")
VALUES (1, 'Jiu Jitsu')
on conflict do UPDATE set "NOME" = 'Jiu Jitsu';

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Branca', 1, 150);
	
INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Cinza', 2, 150);

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Amarela', 3, 150);

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Laranja', 4, 150);

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Verde', 5, 150);

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Azul', 6, 150);

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Roxa', 7, 150);

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Marrom', 8, 150);

INSERT INTO public."GRADUACAO"(
	"CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
	VALUES (1, 'Preta', 9, 150);

INSERT INTO public."USUARIO"(
	"NOME", "APELIDO", "SEXO", "LOGIN", "SENHA")
	VALUES ('Lidson', 'Pitbull', 'M', 'lid', '1212');

INSERT INTO public."ALUNO"(
	"CHAVEUSU", "CHAVEGRD", "NUMAULAS")
	VALUES (2, 7, 0);

INSERT INTO public."PRESENCA"(
	"CHAVEALU", "CHAVETUR")
	VALUES (1, 1);

/* Alterando a versão para 4 */
SELECT setval('public."VERSAOBD"', 4, true);

commit work;
