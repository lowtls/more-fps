# More fps

Mod de [Geode](https://geode-sdk.org) para Geometry Dash que te deja elegir los FPS del juego.

## Valores disponibles

60 · 90 · 120 · 360 · 700 · 1000 · 1500 · 2026 · 5000 · 100000

## Instalación

1. Instala [Geode](https://geode-sdk.org).
2. Descarga `tuusuario.more-fps.geode`.
3. Ponlo en la carpeta `geode/mods` de tu Geometry Dash.
4. Abre el juego y entra a Geode → More fps → Ajustes para elegir el FPS.

## Compilar

Necesitas la [Geode CLI](https://docs.geode-sdk.org/getting-started/geode-cli) y el SDK instalado.

```
geode build
```

El `.geode` queda en la carpeta `build/`.

También puedes compilarlo desde GitHub: pestaña **Actions → Build More fps → Run workflow**.

## Aviso

- Tu monitor no muestra más FPS que su tasa de refresco.
- Valores muy altos pueden volver inestable la física.
- Los FPS altos pueden hacer que tus records no se acepten en el leaderboard.
