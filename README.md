# 🔍 TCP Port Scanner em C

Um scanner de portas TCP simples, leve e multiplataforma desenvolvido em **C**. Ele realiza varreduras em portas de um determinado endereço IP para verificar se elas estão abertas ou fechadas através do *handshake* TCP.

---

## 🚀 Funcionalidades

* **Multiplataforma:** Compatível com **Windows** (utilizando Winsock) e sistemas **Unix-like** (Linux/macOS utilizando sockets POSIX).
* **Varredura por Intervalo:** Permite definir a porta inicial e final para o escaneamento.
* **Leve e Rápido:** Escrito inteiramente em C puro sem dependências pesadas de terceiros.

---

## 🛠️ Como Compilar

### 🐧 Linux / macOS
Utilizando o `gcc`:

```bash
gcc port_scanner.c -o port_scanner  