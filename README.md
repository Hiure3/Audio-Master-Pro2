# AUDIO MASTER PRO
**Professional Audio. Precision Loudness. One Platform.**

Software profissional de processamento de áudio para Windows (C++20 + JUCE).
Estado atual: **Etapa 1.0** (esqueleto que compila, abre uma janela e roda os testes de dB).

## Requisitos
1. **Windows 10/11 x64**
2. **Visual Studio 2022** com o workload *"Desenvolvimento para desktop com C++"*
   (já inclui o compilador MSVC e o CMake)
3. **Git**
4. Internet no primeiro build (o CMake baixa JUCE e Catch2)

## Como compilar
Abra o **"Developer PowerShell for VS 2022"** e rode:

```powershell
git clone https://github.com/SEU-USUARIO/AudioMasterPro.git   # baixa o projeto (troque pelo seu endereço)
cd AudioMasterPro                                              # entra na pasta
cmake --preset windows-release                                 # configura: gera o projeto do Visual Studio e baixa JUCE/Catch2
cmake --build --preset windows-release                         # compila em modo Release
ctest --preset windows-release                                 # executa os testes automatizados
```

O programa fica em:
`build\windows-release\AudioMasterPro_artefacts\Release\Audio Master Pro.exe`

## O que esperar na Etapa 1.0
- Uma janela escura com o título **AUDIO MASTER PRO**
- `ctest` mostrando 4 testes passando (0 falhas)

## Estrutura
Veja `Source/` (Application, UI, Utilities) e `Tests/`. As demais pastas da arquitetura serão preenchidas nas próximas etapas.

## Licença
Pendente de definição (ver `LICENSE`). O JUCE tem licença própria (AGPLv3/comercial).
