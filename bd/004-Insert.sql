INSERT INTO public."USUARIO"(
	"CHAVEUSU", "NOME", "APELIDO", "SEXO", "LOGIN", "SENHA")
	VALUES (1, 'Arlindão', 'Bola de Fogo', 'M', 'adm', 'adm');

INSERT INTO public."PERFIL"(
	"CHAVEUSU", "TIPO")
	VALUES (1, 'A');

INSERT INTO public."MODALIDADE"(
	"CHAVEMOD", "NOME")
VALUES (1, 'Jiu Jitsu')

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

INSERT INTO public."MODALIDADE"(
	"CHAVEMOD", "NOME")
VALUES (2, 'Karatê')

INSERT INTO "GRADUACAO"("CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
VALUES (2, 'Faixa Branca', 1, 180);

INSERT INTO "GRADUACAO"("CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
VALUES (2, 'Faixa Amarela', 2, 180);

INSERT INTO "GRADUACAO"("CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
VALUES (2, 'Faixa Vermelha', 3, 180);

INSERT INTO "GRADUACAO"("CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
VALUES (2, 'Faixa Azul', 4, 180);

INSERT INTO "GRADUACAO"("CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
VALUES (2, 'Faixa Roxa', 5, 180);

INSERT INTO "GRADUACAO"("CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
VALUES (2, 'Faixa Marrom', 6, 180);

INSERT INTO "GRADUACAO"("CHAVEMOD", "NOME", "ORDEM", "MINAULAS")
VALUES (2, 'Faixa Preta', 7, 180);

INSERT INTO public."USUARIO"(
	"CHAVEUSU", "NOME", "APELIDO", "SEXO", "LOGIN", "SENHA")
	VALUES (2, 'Lidson', 'Pitbull', 'M', 'lid', '1212');

INSERT INTO public."PERFIL"(
	"CHAVEUSU", "TIPO")
	VALUES (2, 'C');

INSERT INTO public."ALUNO"(
	"CHAVEUSU", "CHAVEGRD", "NUMAULAS")
	VALUES (2, 17, 0);

INSERT INTO public."TURMA"("CHAVEUSU", "CHAVEMOD", "HRINICIO", "HRFIM", "DIASSEMANA")
VALUES (1, 1, "17:00:00", "18:00:00", "2,3,4");

INSERT INTO public."PRESENCA"(
	"CHAVEALU", "CHAVETUR")
	VALUES (1, 1);

/* Alterando a versão para 4 */
SELECT setval('public."VERSAOBD"', 4, true);

commit work;
