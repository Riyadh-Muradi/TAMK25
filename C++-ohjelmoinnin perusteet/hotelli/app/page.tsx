"use client";

import { HotellinTilanne } from "@/components/hotel-status";
import { VarausLomake } from "@/components/booking-form";
import { HakuLomake } from "@/components/search-form";
import { useTab } from "@/components/tab-provider";

export default function Home() {
  const { activeTab } = useTab();

  return (
    <main className="h-full w-full">
      <div className="mx-auto max-w-6xl">
        {/* Content */}
        <div className="space-y-6">
          {activeTab === "yleiskatsaus" && (
            <div className="space-y-4">
              <div className="group bg-surface relativeflex flex-col overflow-hidden rounded-4xl">
                <div className="p-4 pb-2">
                  <h2 className="text-lg font-semibold">Hotellin tila</h2>
                </div>
                <div className="p-1.5">
                  <HotellinTilanne />
                </div>
              </div>
            </div>
          )}

          {activeTab === "varaus" && (
            <div className="bg-surface grid gap-6 overflow-hidden rounded-4xl p-1.5 md:grid-cols-2">
              <VarausLomake />
              <div className="group relative flex flex-col">
                <div className="border-border/20 border-b p-4 pb-2">
                  <h2 className="text-lg font-semibold">Varauksen tiedot</h2>
                </div>
                <div className="text-muted-foreground space-y-4 p-6">
                  <div>
                    <h4 className="text-foreground mb-2 font-semibold">
                      Hinta
                    </h4>
                    <p>100€ per yö</p>
                  </div>
                  <div>
                    <h4 className="text-foreground mb-2 font-semibold">
                      Huoneet
                    </h4>
                    <p>Valitse huone numerolla 1-50</p>
                  </div>
                </div>
              </div>
            </div>
          )}

          {activeTab === "haku" && (
            <div className="bg-surface grid gap-6 overflow-hidden rounded-4xl p-1.5 md:grid-cols-2">
              <HakuLomake />
              <div className="group relative flex flex-col">
                <div className="border-border/20 border-b p-4 pb-2">
                  <h2 className="text-lg font-semibold">Hakuvinkit</h2>
                </div>
                <div className="text-muted-foreground space-y-4 p-6">
                  <div>
                    <h4 className="text-foreground mb-2 font-semibold">
                      Etsi nimellä
                    </h4>
                    <p>Kirjoita asiakkaan nimi löytääksesi varauksen</p>
                  </div>
                </div>
              </div>
            </div>
          )}
        </div>
      </div>
    </main>
  );
}
