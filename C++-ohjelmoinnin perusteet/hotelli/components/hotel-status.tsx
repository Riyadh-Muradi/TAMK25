"use client";

export function HotellinTilanne() {
  /* Alustava versio - huoneiden määrä ja hinnat */
  const huoneidenMaara = 50;
  const varattujaHuoneita = 12;
  const vapaanaHuoneita = huoneidenMaara - varattujaHuoneita;
  const hintaYolta = 100;

  return (
    <div className="grid gap-4 md:grid-cols-3">
      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <p className="text-muted-foreground text-sm font-medium">
            Kaikkiaan huoneita
          </p>
        </div>
        <div className="p-4 pt-2">
          <div className="text-lg font-semibold">{huoneidenMaara} yhteensä</div>
        </div>
      </div>

      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <p className="text-muted-foreground text-sm font-medium">
            Saatavilla olevat huoneet
          </p>
        </div>
        <div className="p-4 pt-2">
          <div className="text-lg font-semibold">
            {vapaanaHuoneita} saatavilla
          </div>
        </div>
      </div>

      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <p className="text-muted-foreground text-sm font-medium">
            Hinta per yö
          </p>
        </div>
        <div className="p-4 pt-2">
          <div className="text-lg font-semibold">{hintaYolta}€/yö</div>
        </div>
      </div>
    </div>
  );
}
