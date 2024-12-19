#ifndef FUNCOES_H
#define FUNCOES_H

#include "structs.h"

// ========================================================================
// ===================== FUNCOES CRIAÇÃO GRAFO (10) =======================
// ========================================================================

std::set<Vertice> CriarGrafo(std::string nomeArq);

// ========================================================================
// ==================== FUNCOES DE BUSCA GRAFO (11) =======================
// ========================================================================

int BuscarGrafo(std::string nomeArq);

// ========================================================================
// ==================== FUNCOES DE CICLO GRAFO (12) =======================
// ========================================================================

int BuscarCiclo(std::string nomeArq);

// ========================================================================
// ==================== FUNCOES DE CONEXO GRAFO (13) ======================
// ========================================================================

int BuscarComponentes(std::string nomeArq);

// ========================================================================
// =================== FUNCOES DE RELAÇÃO GRAFO (14) ======================
// ========================================================================

int RelacaoPresaPredador(std::string nomeArq);

#endif