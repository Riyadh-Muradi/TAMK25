"use client";

import { useEffect, useState } from "react";
import { toast } from "sonner";

interface HotelData {
  huoneidenMaara: number;
  vapaanaHuoneita: number;
  varatuita: number;
  yksioHinta: number;
  kaksioHinta: number;
}

export function HotellinTilanne() {
  const [data, setData] = useState<HotelData | null>(null);

  useEffect(() => {
    fetch("/api/hotelli")
      .then((res) => res.json())
      .then(setData)
      .catch(() => toast.error("Hotellin tietojen haku epäonnistui"));
  }, []);

  if (!data) return <div className="text-muted-foreground">Ladataan...</div>;

  return (
    <div className="grid gap-4 md:grid-cols-3">
      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <p className="text-muted-foreground text-sm font-medium">
            Kaikkiaan huoneita
          </p>
        </div>
        <div className="p-4 pt-2">
          <div className="text-lg font-semibold">
            {data.huoneidenMaara} yhteensä
          </div>
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
            {data.vapaanaHuoneita} saatavilla
          </div>
        </div>
      </div>

      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <p className="text-muted-foreground text-sm font-medium">
            Varatut huoneet
          </p>
        </div>
        <div className="p-4 pt-2">
          <div className="text-lg font-semibold">{data.varatuita} varattu</div>
        </div>
      </div>

      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <p className="text-muted-foreground text-sm font-medium">
            Yksiö hinta
          </p>
        </div>
        <div className="p-4 pt-2">
          <div className="text-lg font-semibold">{data.yksioHinta}€/yö</div>
        </div>
      </div>

      <div className="group bg-background ring-border/25 relative flex flex-col overflow-hidden rounded-3xl shadow-xs ring-1 outline-none">
        <div className="border-border/50 border-b p-4 pb-2">
          <p className="text-muted-foreground text-sm font-medium">
            Kaksiö hinta
          </p>
        </div>
        <div className="p-4 pt-2">
          <div className="text-lg font-semibold">{data.kaksioHinta}€/yö</div>
        </div>
      </div>
    </div>
  );
}
